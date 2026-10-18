#!/usr/bin/env python3
#
# Go through the ports in this repository and report the ones that are
# behind upstream.
#
# For every port directory (<dir>/Makefile) the version is read from the
# Makefile and compared with the newest upstream version:
#
#   - ports fetched from GitHub (USE_GITHUB, or a github.com URL in
#     MASTER_SITES / WWW) are checked against the latest GitHub release,
#     or the highest version tag when the project has no releases;
#   - everything else is looked up on Repology (https://repology.org)
#     by PORTNAME.
#
# Ports built from a commit (GH_TAGNAME) are reported as "snapshot"
# together with the latest upstream release, so they can be checked by
# hand.
#
# GitHub allows only 60 anonymous API requests per hour; set GITHUB_TOKEN
# (or GH_TOKEN, or log in with gh(1)) to get a higher limit.
#
# Examples:
#
#	./port-outdated.py			# outdated ports of freebsd@sysctl.cz
#	./port-outdated.py -a -v		# all ports, with upstream source
#	./port-outdated.py -H report.html	# portscout-like HTML report
#	./port-outdated.py sniffnet tracy	# only the given ports
#	./port-outdated.py -A			# ports of all maintainers
#
# Exit status: 0 if no port is outdated, 1 if at least one is, 2 on error.
#

import argparse
import datetime
import html
import json
import os
import re
import subprocess
import sys
import threading
import time
import urllib.error
import urllib.parse
import urllib.request
from concurrent.futures import ThreadPoolExecutor

DEFAULT_MAINTAINER = "freebsd@sysctl.cz"
GITHUB_API = "https://api.github.com"
REPOLOGY_API = "https://repology.org/api/v1"
# This repository; distfiles hosted here are not upstream releases.
SELF_REPO = ("Martinfx", "FreeBSD-Ports")
USER_AGENT = "port-outdated/1.0 (+https://github.com/Martinfx/FreeBSD-Ports)"

PRERELEASE_RE = re.compile(r"(alpha|beta|rc|pre|preview|dev|nightly|test)",
    re.IGNORECASE)
GITHUB_URL_RE = re.compile(r"github\.com/([\w.-]+)/([\w.-]+)")


#
# Makefile parsing
#

ASSIGN_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_.]*)\s*([?+:!]?)=\s*(.*)$")
VARREF_RE = re.compile(r"\$\{([A-Za-z_][A-Za-z0-9_.]*)(:[^}]*)?\}")


def read_makefile(path):
	"""Return the top-level variable assignments of a port Makefile.

	This is not a make(1) implementation: conditionals are ignored and
	only plain ${VAR} references are expanded, which is enough for the
	version related variables of almost all ports."""
	with open(path, errors="replace") as f:
		text = f.read()
	text = re.sub(r"\\\n", " ", text)
	vars = {}
	for line in text.splitlines():
		if line.startswith((".", "#", "\t")):
			continue
		m = ASSIGN_RE.match(line)
		if not m:
			continue
		name, op, value = m.groups()
		value = value.split("#", 1)[0].strip()
		if op == "?" and name in vars:
			continue
		if op == "+" and name in vars:
			value = vars[name] + " " + value
		vars[name] = value
	return vars


def expand(value, vars, depth=0):
	if value is None or depth > 10:
		return value

	def sub(m):
		name, mods = m.groups()
		if mods or name not in vars:
			return m.group(0)
		return expand(vars[name], vars, depth + 1)

	return VARREF_RE.sub(sub, value)


def port_info(portdir):
	vars = read_makefile(os.path.join(portdir, "Makefile"))
	get = lambda name: expand(vars.get(name), vars)
	portname = get("PORTNAME") or os.path.basename(portdir)
	version = get("DISTVERSION") or get("PORTVERSION")
	info = {
		"port": os.path.basename(portdir),
		"portname": portname,
		"maintainer": (get("MAINTAINER") or "").strip(),
		"version": version,
		"prefix": get("DISTVERSIONPREFIX") or "",
		"tagname": get("GH_TAGNAME"),
		"github": None,
	}

	use_github = (get("USE_GITHUB") or "").lower()
	if use_github in ("yes", "") and (use_github or get("GH_ACCOUNT")):
		info["github"] = (get("GH_ACCOUNT") or portname,
		    get("GH_PROJECT") or portname)
	if info["github"] is None:
		# Only the project home page and the primary master site;
		# further MASTER_SITES usually point to dependencies.
		sites = (get("MASTER_SITES") or "").split()
		for url in (get("WWW") or "", sites[0] if sites else ""):
			m = GITHUB_URL_RE.search(url)
			if m and (m.group(1), m.group(2)) != SELF_REPO:
				info["github"] = (m.group(1),
				    re.sub(r"\.git$", "", m.group(2)))
				break
	return info


#
# Version handling
#

def version_key(v):
	"""Split a version into comparable parts: numbers compare
	numerically, and pre-release words (alpha, beta, rc, ...) sort
	before the release they precede."""
	key = []
	for tok in re.findall(r"\d+|[a-zA-Z]+", v):
		if tok.isdigit():
			key.append((2, int(tok), ""))
		elif PRERELEASE_RE.fullmatch(tok):
			key.append((0, 0, tok.lower()))
		else:
			key.append((1, 0, tok.lower()))
	# A release ranks above its pre-releases: 1.0 > 1.0rc1.
	key.append((1, 0, ""))
	return key


def clean_tag(tag, prefix, portname):
	"""Turn a git tag into a version comparable with DISTVERSION."""
	if prefix and tag.startswith(prefix):
		return tag[len(prefix):]
	for p in (portname + "-", portname + "_", "release-", "release_",
	    "version-", "v.", "v_", "v"):
		if tag.lower().startswith(p.lower()) and \
		    tag[len(p):len(p) + 1].isdigit():
			return tag[len(p):]
	m = re.search(r"\d.*", tag)
	return m.group(0) if m else tag


def looks_like_version(v):
	return bool(re.match(r"\d", v or ""))


#
# Upstream lookups
#

class Upstream:
	def __init__(self, github_api, repology_api, token):
		self.github_api = github_api
		self.repology_api = repology_api
		self.token = token
		self.repology_lock = threading.Lock()
		self.repology_last = 0.0
		self.rate_limited = False

	def get(self, url, headers=None):
		h = {"User-Agent": USER_AGENT}
		h.update(headers or {})
		req = urllib.request.Request(url, headers=h)
		with urllib.request.urlopen(req, timeout=60) as resp:
			return json.load(resp)

	def github(self, path):
		headers = {"Accept": "application/vnd.github+json"}
		if self.token:
			headers["Authorization"] = "Bearer " + self.token
		try:
			return self.get(self.github_api + path, headers)
		except urllib.error.HTTPError as e:
			if e.code == 404:
				return None
			if e.code in (403, 429):
				self.rate_limited = True
			raise

	def github_latest(self, account, project, prefix, portname,
	    want_prerelease):
		repo = "/repos/%s/%s" % (urllib.parse.quote(account),
		    urllib.parse.quote(project))
		rel = self.github(repo + "/releases/latest")
		if rel and rel.get("tag_name"):
			v = clean_tag(rel["tag_name"], prefix, portname)
			if looks_like_version(v):
				return v
		tags = self.github(repo + "/tags?per_page=100") or []
		versions = [clean_tag(t["name"], prefix, portname)
		    for t in tags]
		versions = [v for v in versions if looks_like_version(v) and
		    (want_prerelease or not PRERELEASE_RE.search(v))]
		return max(versions, key=version_key) if versions else None

	def repology_latest(self, name):
		# Repology asks for at most one request per second.
		with self.repology_lock:
			wait = self.repology_last + 1.0 - time.time()
			if wait > 0:
				time.sleep(wait)
			self.repology_last = time.time()
		try:
			pkgs = self.get("%s/project/%s" % (self.repology_api,
			    urllib.parse.quote(name.lower(), safe="")))
		except urllib.error.HTTPError as e:
			if e.code == 404:
				return None
			raise
		newest = [p["version"] for p in pkgs or []
		    if p.get("status") == "newest"]
		return max(newest, key=version_key) if newest else None


def check_port(info, upstream):
	r = dict(info, upstream=None, source=None, status="unknown", note="")
	current = info["version"]
	if not current or "$" in current:
		r["note"] = "cannot determine version from Makefile"
		return r
	want_pre = bool(PRERELEASE_RE.search(current))
	try:
		if info["github"]:
			r["source"] = "github:%s/%s" % info["github"]
			r["upstream"] = upstream.github_latest(*info["github"],
			    info["prefix"], info["portname"], want_pre)
		if r["upstream"] is None:
			v = upstream.repology_latest(info["portname"])
			if v:
				r["source"], r["upstream"] = "repology", v
	except (urllib.error.URLError, OSError, ValueError) as e:
		r["note"] = "lookup failed: %s" % e
		return r

	if r["upstream"] is None:
		r["note"] = "no upstream version found"
	elif info["tagname"]:
		r["status"] = "snapshot"
		r["note"] = "built from commit %s" % info["tagname"][:12]
	elif version_key(clean_tag(current, info["prefix"],
	    info["portname"])) < version_key(r["upstream"]):
		r["status"] = "outdated"
	else:
		r["status"] = "ok"
	return r


#
# Main
#

def github_token():
	token = os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")
	if token:
		return token
	try:
		return subprocess.run(["gh", "auth", "token"],
		    capture_output=True, text=True, check=True).stdout.strip()
	except (OSError, subprocess.CalledProcessError):
		return None


def find_ports(top, names):
	if names:
		dirs = [os.path.join(top, n.rstrip("/")) for n in names]
	else:
		dirs = [os.path.join(top, d) for d in sorted(os.listdir(top))]
	return [d for d in dirs if os.path.isfile(os.path.join(d, "Makefile"))]


def print_table(rows, verbose):
	header = ["PORT", "CURRENT", "UPSTREAM", "STATUS"]
	if verbose:
		header += ["SOURCE", "NOTE"]
	table = [header]
	for r in rows:
		line = [r["port"], r["version"] or "-", r["upstream"] or "-",
		    r["status"]]
		if verbose:
			line += [r["source"] or "-", r["note"]]
		table.append(line)
	widths = [max(len(row[i]) for row in table)
	    for i in range(len(header))]
	for row in table:
		print("  ".join(c.ljust(w) for c, w in zip(row, widths)).rstrip())


HTML_TEMPLATE = """<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Ports of %(maintainer)s</title>
<style>
body { font-family: sans-serif; margin: 1em; }
table { border-collapse: collapse; }
th, td { padding: 0.2em 0.8em; border-bottom: 1px solid #ccc; text-align: left; }
th { background: #eee; }
tr.outdated td { background: #fdd; }
tr.snapshot td { background: #ffd; }
tr.unknown td { color: #888; }
</style>
</head>
<body>
<h1>Ports of %(maintainer)s</h1>
<p>%(summary)s<br>Generated %(date)s.</p>
<table>
<tr><th>Port</th><th>Current</th><th>New</th><th>Status</th><th>Source</th><th>Note</th></tr>
%(rows)s
</table>
</body>
</html>
"""

STATUS_ORDER = {"outdated": 0, "snapshot": 1, "unknown": 2, "ok": 3}


def source_link(r):
	if r["source"] and r["source"].startswith("github:"):
		url = "https://github.com/%s/%s/releases" % r["github"]
	elif r["source"] == "repology":
		url = "https://repology.org/project/%s/versions" % \
		    urllib.parse.quote(r["portname"].lower())
	else:
		return "-"
	return '<a href="%s">%s</a>' % (html.escape(url),
	    html.escape(r["source"]))


def write_html(path, rows, maintainer, summary):
	esc = lambda v: html.escape(v or "-")
	lines = []
	for r in sorted(rows, key=lambda r: (STATUS_ORDER[r["status"]],
	    r["port"])):
		lines.append('<tr class="%s"><td>%s</td><td>%s</td><td>%s</td>'
		    "<td>%s</td><td>%s</td><td>%s</td></tr>" % (r["status"],
		    esc(r["port"]), esc(r["version"]),
		    esc(r["upstream"] if r["status"] != "ok" else ""),
		    r["status"], source_link(r), html.escape(r["note"])))
	with open(path, "w") as f:
		f.write(HTML_TEMPLATE % {
			"maintainer": html.escape(maintainer),
			"summary": html.escape(summary),
			"date": datetime.datetime.now().strftime(
			    "%Y-%m-%d %H:%M"),
			"rows": "\n".join(lines),
		})


def main():
	ap = argparse.ArgumentParser(
	    description="Report ports in this repository that are behind "
	    "upstream.")
	ap.add_argument("ports", nargs="*",
	    help="port directories to check (default: all)")
	ap.add_argument("-m", "--maintainer", default=DEFAULT_MAINTAINER,
	    help="only ports with this MAINTAINER (default: %(default)s)")
	ap.add_argument("-A", "--any-maintainer", action="store_true",
	    help="check ports of all maintainers")
	ap.add_argument("-a", "--all", action="store_true",
	    help="show all ports, not only outdated and snapshot ones")
	ap.add_argument("-v", "--verbose", action="store_true",
	    help="also show where the upstream version came from")
	ap.add_argument("-j", "--json", action="store_true",
	    help="print results as JSON")
	ap.add_argument("-H", "--html", metavar="FILE",
	    help="also write a portscout-like HTML report of all checked "
	    "ports to FILE")
	ap.add_argument("-C", "--directory",
	    default=os.path.dirname(os.path.abspath(__file__)),
	    help="ports repository (default: directory of this script)")
	ap.add_argument("--jobs", type=int, default=8, help=argparse.SUPPRESS)
	ap.add_argument("--github-api", default=GITHUB_API,
	    help=argparse.SUPPRESS)
	ap.add_argument("--repology-api", default=REPOLOGY_API,
	    help=argparse.SUPPRESS)
	args = ap.parse_args()

	infos = [port_info(d) for d in find_ports(args.directory, args.ports)]
	if not args.any_maintainer and not args.ports:
		infos = [i for i in infos
		    if i["maintainer"].lower() == args.maintainer.lower()]
	if not infos:
		print("port-outdated: no ports found", file=sys.stderr)
		return 2

	upstream = Upstream(args.github_api, args.repology_api,
	    github_token())
	with ThreadPoolExecutor(max_workers=args.jobs) as pool:
		rows = list(pool.map(lambda i: check_port(i, upstream), infos))

	counts = {}
	for r in rows:
		counts[r["status"]] = counts.get(r["status"], 0) + 1
	shown = rows if args.all else \
	    [r for r in rows if r["status"] in ("outdated", "snapshot")]

	summary = "%d ports checked: %s." % (len(rows), ", ".join(
	    "%d %s" % (n, s) for s, n in sorted(counts.items())))
	if args.html:
		write_html(args.html, rows, "all maintainers" if
		    args.any_maintainer else args.maintainer, summary)

	if args.json:
		json.dump(shown, sys.stdout, indent=2)
		print()
	else:
		if shown:
			print_table(shown, args.verbose)
			print()
		print(summary)
		if upstream.rate_limited:
			print("GitHub API refused some requests (rate limit?)%s." %
			    ("" if upstream.token else
			    "; set GITHUB_TOKEN to check all ports"),
			    file=sys.stderr)
		if counts.get("unknown") and not args.all:
			print("Run with -a -v to see ports whose upstream "
			    "version is unknown.")

	return 1 if counts.get("outdated") else 0


if __name__ == "__main__":
	sys.exit(main())

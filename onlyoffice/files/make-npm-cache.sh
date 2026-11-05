#!/bin/sh
# Maintainer helper: generate the npm cache of the port.
#
# The build installs the npm modules of web-apps and of the three vite
# projects of the start page (desktop-apps/common/loginpage) offline, from
# an npm cache that is a distfile, see the Makefile.  This
# script fills such a cache by running the same "npm install" commands as
# the port, with network access, for FreeBSD on amd64 and arm64.  Run it
# on the patched source tree of the port (after
# "make patch", which also installs the lockfiles of the start page), on
# a host with network access; it does not have to be FreeBSD, npm is told
# that it installs for FreeBSD.
#
# usage: make-npm-cache.sh <WRKSRC> <output directory> [npm command ...]
#
# Every npm command given (default: npm) runs the whole sequence into the
# same cache.  npm asks the registry for the metadata of a package in a
# form (full documents or abbreviated ones) that depends on its version and
# on what it resolves, and finds in the cache only the form it asks for, so
# run the script with the npm of www/npm${NODEJS_SUFFIX} and with an older
# npm, for example "npx -y npm@11", to get a cache that works with both.
#
# The cache (<output directory>/_cacache) is kept in the onlyoffice-distfiles
# branch of the FreeBSD-Ports repository, with _cacache at the root of the
# tree: replace it there, commit, tag the commit
# onlyoffice-npm-cache-<build tag>-<date>, push the branch and the tag, set
# _NPM_CACHE_TAG in the port Makefile to the tag and run "make makesum"
# (the port fetches the archive of the tag through its GH_TUPLE).
#
# When a port update changes the npm dependencies, regenerate the
# lockfiles of the start page projects first (they ship none), with
# network access, and put them in files/ (post-patch installs them):
#   cd <WRKSRC>/desktop-apps/common/loginpage
#   for d in . addondialog noconnect; do (cd $d && npm install --package-lock-only); done

set -eu

if [ $# -lt 2 ]; then
	echo "usage: $0 <WRKSRC> <output directory> [npm command ...]" >&2
	exit 1
fi

SRC=$(cd "$1" && pwd)
mkdir -p "$2"
OUT=$(cd "$2" && pwd)
shift 2
if [ $# -eq 0 ]; then
	set -- npm
fi
WORK=$(mktemp -d)
trap 'rm -rf "${WORK}"' EXIT
CACHE=${WORK}/.npm
# an empty user config, so that ~/.npmrc of the maintainer plays no part
: > "${WORK}/npmrc"

LOGINPAGE=desktop-apps/common/loginpage

for npm in "$@"; do
	for cpu in x64 arm64; do
		# work on a copy, "npm install <package>" edits package.json
		rm -rf "${WORK}/src"
		for d in web-apps/build ${LOGINPAGE} ${LOGINPAGE}/addondialog \
		    ${LOGINPAGE}/noconnect; do
			mkdir -p "${WORK}/src/${d}"
			cp "${SRC}/${d}/package.json" "${SRC}/${d}/package-lock.json" \
				"${WORK}/src/${d}"
		done

		# the same commands as the Makefile, build_tools/scripts/build_js.py
		# and desktop-apps/common/loginpage/build/build_all.py run, with the
		# same environment
		run() {
			dir=$1
			shift
			echo "===> ${npm} (${cpu}): $* in ${dir}"
			(cd "${WORK}/src/${dir}" && HOME=${WORK} NODE_ENV=production \
				${npm} --cache "${CACHE}" --userconfig "${WORK}/npmrc" \
				--registry https://registry.npmjs.org/ \
				--os freebsd --cpu "${cpu}" --ignore-scripts \
				--no-audit --no-fund "$@")
		}
		run web-apps/build install patch-package
		run web-apps/build install optipng-bin@5.1.0
		run web-apps/build install
		run ${LOGINPAGE} install
		run ${LOGINPAGE}/addondialog install
		run ${LOGINPAGE}/noconnect install
	done
done

rm -rf "${OUT}/_cacache"
mv "${CACHE}/_cacache" "${OUT}/_cacache"
echo "created ${OUT}/_cacache"
du -sh "${OUT}/_cacache"

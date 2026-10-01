#!/bin/sh
# Maintainer helper: generate the prefetched node_modules distfile.
#
# pnpm >= 11 ships as a native binary that does not exist for FreeBSD, so this
# script has to be run on a host where pnpm works (Linux or macOS) with network
# access.  It installs the dependencies of the given podman-desktop source tree
# for FreeBSD (the optional native packages of esbuild, rolldown, rollup,
# lightningcss and tailwindcss are selected for freebsd/x64) without running any
# lifecycle script, and archives every node_modules directory.
#
# usage: make-node-modules-archive.sh <podman-desktop source dir> <output .tar.xz>
#
# Upload the result as a release asset of the podman-desktop fork, see
# MASTER_SITES in the port Makefile, then run "make makesum".

set -eu

if [ $# -ne 2 ]; then
	echo "usage: $0 <podman-desktop source dir> <output .tar.xz>" >&2
	exit 1
fi

SRC=$(cd "$1" && pwd)
OUT=$(cd "$(dirname "$2")" && pwd)/$(basename "$2")
WORK=$(mktemp -d)
trap 'rm -rf "${WORK}"' EXIT

# work on a copy so the source tree is left untouched
(cd "${SRC}" && tar cf - --exclude=node_modules --exclude=.git .) | (cd "${WORK}" && tar xf -)
cd "${WORK}"

cat >> pnpm-workspace.yaml <<'EOF'

supportedArchitectures:
  os: [freebsd]
  cpu: [x64]
EOF

ELECTRON_SKIP_BINARY_DOWNLOAD=1 PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1 \
	pnpm install --frozen-lockfile --ignore-scripts \
	--config.engine-strict=false \
	--store-dir="${WORK}/.pnpm-store" \
	--filter='!website' --filter='!website-argos' --filter='!storybook' \
	--filter='!./tests/**'

find . -name .pnpm-store -prune -o -name node_modules -prune -type d -print | sort > "${WORK}/.list"
# reproducible archive (GNU tar)
tar --sort=name --mtime=@0 --owner=0 --group=0 --numeric-owner \
	-cJf "${OUT}" -T "${WORK}/.list"
echo "created ${OUT}"

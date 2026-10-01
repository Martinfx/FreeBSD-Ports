#!/bin/sh
# Build Podman Desktop without pnpm: pnpm >= 11 is distributed as a native
# binary that is not available for FreeBSD, so the steps of the root
# "build" script of package.json are replicated here, using the prefetched
# node_modules.

set -eu

SRCDIR=$(pwd)
PATH=${SRCDIR}/node_modules/.bin:${PATH}
export PATH

run() {
	echo "===> $*"
	"$@"
}

# core API, main process and preloads
for pkg in api main preload preload-docker-extension preload-webview; do
	(cd "${SRCDIR}/packages/${pkg}" && run vite build)
done

# generated preload typings
run dts-cb -i packages/preload/tsconfig.json \
	-o packages/preload/exposedInMainWorld.d.ts
run dts-cb -i packages/preload-docker-extension/tsconfig.json \
	-o packages/preload-docker-extension/exposedInDockerExtension.d.ts
run dts-cb -i packages/preload-webview/tsconfig.json \
	-o packages/preload-webview/exposedInWebview.d.ts

# shared UI components and the renderer
(cd "${SRCDIR}/packages/ui" && run svelte-package)
NODE_OPTIONS=--max-old-space-size=4096 run vite -c packages/renderer/vite.config.ts build

# built-in extensions
for ext in compose docker/packages/extension podman-docker-context lima \
    podman/packages/extension kube-context kind registries kubectl-cli; do
	(
		cd "${SRCDIR}/extensions/${ext}"
		# scripts/download.ts is skipped on purpose: it fetches Linux, macOS
		# and Windows binaries (podman installers, kind) from GitHub, which
		# are useless on FreeBSD and the build has no network access.
		run vite build
		if [ -f scripts/build.cjs ]; then
			run node ./scripts/build.cjs
		else
			run node ./scripts/build.js
		fi
	)
done

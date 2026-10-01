PORTNAME=	podman-desktop
# snapshot of 1.31.0-next with FreeBSD support, see PD_COMMIT
PORTVERSION=	1.30.99.20261001
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/Martinfx/podman-desktop/archive/:source \
		https://raw.githubusercontent.com/Martinfx/FreeBSD-Ports/podman-desktop-distfiles/podman-desktop/:nodemodules
DISTFILES=	${PD_COMMIT}.tar.gz:source \
		${_PD_NODE_MODULES}.00:nodemodules \
		${_PD_NODE_MODULES}.01:nodemodules
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PD_COMMIT}.tar.gz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Graphical tool for managing containers, images and pods with Podman
WWW=		https://podman-desktop.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	prefetched native node modules (esbuild, rolldown, lightningcss, tailwindcss) are only built for freebsd-x64

# electron is copied into DATADIR at install time, the shared libraries it
# links to are declared below
BUILD_DEPENDS=	${ELECTRON_DIR}/electron:devel/electron${ELECTRON_VER}
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libatk-bridge-2.0.so:accessibility/at-spi2-core \
		libatspi.so:accessibility/at-spi2-core \
		libcups.so:print/cups \
		libdav1d.so:multimedia/dav1d \
		libdbus-1.so:devel/dbus \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libFLAC.so:audio/flac \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libopenh264.so:multimedia/openh264 \
		libopus.so:audio/opus \
		libpci.so:devel/libpci \
		libpipewire-0.3.so:multimedia/pipewire \
		libsndio.so:audio/sndio \
		libwebp.so:graphics/webp \
		libxkbcommon.so:x11/libxkbcommon \
		libxshmfence.so:x11/libxshmfence
RUN_DEPENDS=	podman:sysutils/podman \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext-runtime gl gnome jpeg nodejs:24,build \
		xorg
USE_GL=		gbm gl
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 libxml2 libxslt pango
USE_XORG=	x11 xcb xcomposite xdamage xext xfixes xi xrandr xrender xtst

# commit of https://github.com/Martinfx/podman-desktop carrying the FreeBSD
# support, regenerate the node_modules distfile when it changes, see
# files/make-node-modules-archive.sh
PD_COMMIT=	5686e83151678419b6cba9ec4a8b65965d4f0cb5
ELECTRON_VER=	42
ELECTRON_DIR=	${LOCALBASE}/share/electron${ELECTRON_VER}
# split in parts below the GitHub file size limit
_PD_NODE_MODULES=	${PORTNAME}-${PORTVERSION}-node-modules.tar.xz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PD_COMMIT}

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		MODE=production \
		VITE_APP_VERSION=${PORTVERSION}

SUB_FILES=	podman-desktop pkg-message
SUB_LIST=	DATADIR=${DATADIR}

APP_DIR=	${DATADIR}/resources/app

# pnpm >= 11 is distributed as a native binary that does not exist for
# FreeBSD, so the steps of the "build" script of package.json are run
# directly with the tools of the prefetched node_modules
_PD_ENV=	${MAKE_ENV} PATH=${WRKSRC}/node_modules/.bin:${PATH}
_PD_PACKAGES=	api main preload preload-docker-extension preload-webview
_PD_PRELOAD_TYPES=	preload:exposedInMainWorld \
			preload-docker-extension:exposedInDockerExtension \
			preload-webview:exposedInWebview
# scripts/download.ts of the extensions is not run on purpose: it fetches
# Linux, macOS and Windows binaries (podman installers, kind) from GitHub
_PD_EXTENSIONS=	compose docker/packages/extension podman-docker-context lima \
		podman/packages/extension kube-context kind registries kubectl-cli

PLIST_FILES=	bin/podman-desktop \
		share/applications/podman-desktop.desktop \
		share/pixmaps/podman-desktop.png

# extracted after the extract phase on purpose: extract-fixup-modes runs a
# recursive chmod(1) over WRKDIR which fails on the ~110k node_modules entries
post-patch:
	@${CAT} ${DISTDIR}/${DIST_SUBDIR}/${_PD_NODE_MODULES}.0[0-9] | \
		${TAR} -xf - -C ${WRKSRC}

do-build:
.for p in ${_PD_PACKAGES}
	@cd ${WRKSRC}/packages/${p} && ${SETENV} ${_PD_ENV} vite build
.endfor
.for t in ${_PD_PRELOAD_TYPES}
	@cd ${WRKSRC} && ${SETENV} ${_PD_ENV} dts-cb \
		-i packages/${t:C/:.*//}/tsconfig.json \
		-o packages/${t:C/:.*//}/${t:C/.*://}.d.ts
.endfor
	@cd ${WRKSRC}/packages/ui && ${SETENV} ${_PD_ENV} svelte-package
	@cd ${WRKSRC} && ${SETENV} ${_PD_ENV} NODE_OPTIONS=--max-old-space-size=4096 \
		vite -c packages/renderer/vite.config.ts build
.for e in ${_PD_EXTENSIONS}
	@cd ${WRKSRC}/extensions/${e} && ${SETENV} ${_PD_ENV} vite build && \
		if [ -f scripts/build.cjs ]; then \
			${SETENV} ${_PD_ENV} node ./scripts/build.cjs; \
		else \
			${SETENV} ${_PD_ENV} node ./scripts/build.js; \
		fi
.endfor

do-install:
	# private copy of electron, so process.resourcesPath points to our resources
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${ELECTRON_DIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${RM} ${STAGEDIR}${DATADIR}/resources/default_app.asar
	${INSTALL_PROGRAM} ${ELECTRON_DIR}/electron ${STAGEDIR}${DATADIR}/podman-desktop
	@${RM} ${STAGEDIR}${DATADIR}/electron
	# same electron fuses as the upstream builds (.electron-builder.config.cjs)
	@cd ${WRKSRC} && ${LOCALBASE}/bin/node ${FILESDIR}/flip-fuses.cjs \
		${STAGEDIR}${DATADIR}/podman-desktop
	@${FIND} ${STAGEDIR}${DATADIR} -name '*.so*' -exec ${CHMOD} ${BINMODE} {} +
	# application, same file set as "files" in .electron-builder.config.cjs
	@${MKDIR} ${STAGEDIR}${APP_DIR}
	${INSTALL_DATA} ${WRKSRC}/package.json ${STAGEDIR}${APP_DIR}
	${INSTALL_DATA} ${WRKSRC}/product.json ${STAGEDIR}${DATADIR}/resources
	@cd ${WRKSRC} && for d in packages/*/dist packages/main/src/assets \
	    extensions/*/builtin extensions/*/packages/*/builtin; do \
		[ -d "$${d}" ] || continue; \
		${MKDIR} ${STAGEDIR}${APP_DIR}/$${d}; \
		(cd $${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_DIR}/$${d}); \
	done
	# runtime dependencies of the main process (externals of packages/main)
	@cd ${WRKSRC} && ${LOCALBASE}/bin/node ${FILESDIR}/copy-prod-deps.mjs . \
		${STAGEDIR}${APP_DIR}/node_modules
	${INSTALL_SCRIPT} ${WRKDIR}/podman-desktop ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/buildResources/icon-512x512.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/podman-desktop.png
	${INSTALL_DATA} ${FILESDIR}/podman-desktop.desktop \
		${STAGEDIR}${PREFIX}/share/applications

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} -not -type d | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>

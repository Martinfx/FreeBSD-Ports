PORTNAME=	podman-desktop
# snapshot of 1.31.0-next with FreeBSD support, see PD_COMMIT
PORTVERSION=	1.30.99.20261001
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/Martinfx/podman-desktop/archive/:source \
		https://github.com/Martinfx/podman-desktop/releases/download/freebsd-${PORTVERSION}/:nodemodules
DISTFILES=	${PD_COMMIT}.tar.gz:source \
		${PORTNAME}-${PORTVERSION}-node-modules.tar.xz:nodemodules
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PD_COMMIT}.tar.gz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Graphical tool for managing containers, images and pods with Podman
WWW=		https://podman-desktop.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	prefetched native node modules (esbuild, rolldown, lightningcss, tailwindcss) are only built for freebsd-x64

# electron is copied into DATADIR at install time and its shared library
# dependencies are needed at run time
BUILD_DEPENDS=	${ELECTRON_DIR}/electron:devel/electron${ELECTRON_VER}
RUN_DEPENDS=	${ELECTRON_DIR}/electron:devel/electron${ELECTRON_VER} \
		podman:sysutils/podman \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils nodejs:24,build

# commit of https://github.com/Martinfx/podman-desktop carrying the FreeBSD
# support, regenerate the node_modules distfile when it changes, see
# files/make-node-modules-archive.sh
PD_COMMIT=	5686e83151678419b6cba9ec4a8b65965d4f0cb5
ELECTRON_VER=	42
ELECTRON_DIR=	${LOCALBASE}/share/electron${ELECTRON_VER}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PD_COMMIT}

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 \
		MODE=production \
		VITE_APP_VERSION=${PORTVERSION}

SUB_FILES=	podman-desktop pkg-message
SUB_LIST=	DATADIR=${DATADIR}

APP_DIR=	${DATADIR}/resources/app

PLIST_FILES=	bin/podman-desktop \
		share/applications/podman-desktop.desktop \
		share/pixmaps/podman-desktop.png

post-extract:
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${PORTVERSION}-node-modules.tar.xz \
		-C ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ${FILESDIR}/build.sh

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

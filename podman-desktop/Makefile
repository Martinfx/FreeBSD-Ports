PORTNAME=	podman-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.1
CATEGORIES=	sysutils
MAINTAINER=	maxfx@hades
COMMENT=	podman desktop
WWW=		https://podman-desktop.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase:ldflags nodejs:20,build

USE_GITHUB=	yes
GH_ACCOUNT=	podman-desktop
GH_PROJECT=	podman-desktop


EXTRACT_DEPENDS= jq:textproc/jq \
		 node${NODEJS_VERSION}>0:www/node${NODEJS_VERSION}

BUILD_DEPENDS=	app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
#		jq:textproc/jq \
		npm:www/npm-node18 \
		yarn:www/yarn-node18

LIB_DEPENDS=	libvips.so:graphics/vips

MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		HOME=${WRKDIR} \
		USE_SYSTEM_APP_BUILDER=true	 \
		SOURCE_DATE_EPOCH=${_BUILD_DATE} \
		PATH=${WRKSRC}/node_modules/.bin:${LOCALBASE}/bin:${PATH}

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
# Don't download browser binaries on playwright node_modules installation
MAKE_ENV+=	PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=true \
		PLAYWRIGHT_SKIP_VALIDATE_HOST_REQUIREMENTS=true \
		PLAYWRIGHT_BROWSERS_PATH="/nonexistent"

ELECTRON_VER_MAJOR=	30

ELECTRON_DOWNLOAD_URL=	https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	/sbin/sha256 -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

#USE_ELECTRON=	prefetch extract rebuild:electron build:builder
#
pre-build:
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

do-build: install-node-modules patch-node-modules

install-node-modules:
	# install node_modules without executing post-installation scripts
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn --ignore-scripts #--offline
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		yarn postinstall  #--offline

patch-node-modules:
	# patch install node modules before building native node modules
	for p in ${PATCHDIR}/node_modules/patch-*; do \
		${PATCH} -p0 -s -d ${WRKSRC} < $${p}; \
        done

do-build:

	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn install --verbose

.include <bsd.port.mk>

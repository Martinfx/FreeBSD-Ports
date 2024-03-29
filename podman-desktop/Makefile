PORTNAME=	podman-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.202404051435-892b7e7
CATEGORIES=	sysutils

MAINTAINER=	maxfx@hades
COMMENT=	podman desktop

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase:ldflags nodejs:18

USE_GITHUB=	yes
GH_ACCOUNT=	containers
GH_PROJECT=	podman-desktop

BUILD_DEPENDS=	app-builder>0:devel/app-builder \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
#		jq:textproc/jq \
		npm:www/npm-node18 \
		yarn:www/yarn-node18

LIB_DEPENDS=	libvips.so:graphics/vips 

MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
#		HOME=${WRKDIR} \
		USE_SYSTEM_APP_BUILDER=true \
#		SOURCE_DATE_EPOCH=${_BUILD_DATE} \
		PATH=${WRKSRC}/node_modules/.bin:${LOCALBASE}/bin:${PATH}

MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
# Don't download browser binaries on playwright node_modules installation
MAKE_ENV+=	PLAYWRIGHT_BROWSERS_PATH=${WRKDIR}/pw-browsers \
		PLAYWRIGHT_SKIP_BROWSER_DOWNLOAD=1

ELECTRON_VER_MAJOR=	25



USE_ELECTRON=	prefetch extract rebuild:electron build:builder

pre-build:
	@${RM} -r ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	@${CP} -pR ${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} ${WRKDIR}/electron${ELECTRON_VER_MAJOR}
	${CHMOD} -R a+w ${WRKDIR}/electron${ELECTRON_VER_MAJOR}

do-build: patch-node-modules
patch-node-modules:
	# patch install node modules before building native node modules
	for p in ${PATCHDIR}/node_modules/patch-*; do \
		${PATCH} -p0 -s -d ${WRKSRC} < $${p}; \
        done

do-build:

	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn install --verbose

.include <bsd.port.mk>

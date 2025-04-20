PORTNAME=	podman-desktop
DISTVERSIONPREFIX=v
DISTVERSION=	1.18.0
CATEGORIES=	deskutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Graphical tool for developing on containers and Kubernetes
WWW=		https://podman-desktop.io

LICENSE=	APACHE20

ONLY_FOR_ARCHS= amd64

BUILD_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}

USES=		nodejs:22,build

USE_GITHUB=	yes
GH_ACCOUNT=	podman-desktop
GH_PROJECT=	podman-desktop

PACKAGE_ENV+=	npm_config_runtime=electron \
		npm_config_target=${ELECTRON_VER_MAJOR} \
		npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers
MAKE_ENV+=	ELECTRON_OVERRIDE_DIST_PATH=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR} \
		HOME=${WRKDIR} \
		ELECTRON_SKIP_BINARY_DOWNLOAD=1 \

_ELECTRON_VERSION=	34
.include <../../devel/electron${_ELECTRON_VERSION}/Makefile.version>

#NODEJS_DIR=	${.CURDIR:H:H}/www/node20
#.include "${NODEJS_DIR}/Makefile.version"
#ELECTRON_DIR=	${.CURDIR:H:H}/devel/electron34
#.include "${ELECTRON_DIR}/Makefile.version"

ELECTRON_DOWNLOAD_URL=	https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	/sbin/sha256 -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_ARCH=	${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

do-build:
#	${ECHO_CMD} offline=true >> ${WRKSRC}/.npmrc
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm config set cache ${WRKDIR}/node_modules
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --prefer-offline
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn add --ignore-scripts pnpm@10.6.3

.include <bsd.port.mk>

PORTNAME=	teams-for-linux
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1
CATEGORIES=	net-im

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Unofficial Microsoft Teams for Linux client
WWW=		https://github.com/IsmaelMartinez/teams-for-linux

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm${NODEJS_SUFFIX}>0:www/npm${NODEJS_SUFFIX}

USES=		desktop-file-utils gl gmake gnome gssapi:mit iconv:wchar_t \
		jpeg localbase:ldflags nodejs:22,build pkgconfig python:build \
		shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	IsmaelMartinez
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
NODEJS_DIR=	${.CURDIR:H:H}/www/node22
.include "${NODEJS_DIR}/Makefile.version"
ELECTRON_DIR=	${.CURDIR:H:H}/devel/electron37
.include "${ELECTRON_DIR}/Makefile.version"

ELECTRON_DOWNLOAD_URL=	https://github.com/electron/electron/releases/download/v${ELECTRON_VER}
ELECTRON_DOWNLOAD_URL_HASH!=	/sbin/sha256 -q -s ${ELECTRON_DOWNLOAD_URL}
ELECTRON_ARCH=		${ARCH:S/aarch64/arm64/:S/amd64/x64/:S/i386/ia32/}

# Don't download electron binary distribution on electron node_modules installation
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1 PYTHONDONTWRITEBYTECODE=1

pre-build:
	# rebuild native node modules in top directory
	@for subdir in `${FIND} ${WRKSRC}/node_modules -type f -name binding.gyp -exec ${DIRNAME} {} ';'`; do \
		${ECHO_MSG} "===>   Rebuilding native modules in $${subdir}"; \
		cd $${subdir} && \
		${SETENV} ${MAKE_ENV} \
			npm_config_runtime=electron \
			npm_config_target=${ELECTRON_VER} \
			npm_config_nodedir=${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers \
			node-gyp --userconfig=${WRKSRC}/.npmrc rebuild; \
	done

do-install:


.include <bsd.port.mk>

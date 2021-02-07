# $FreeBSD$

PORTNAME=	Signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.40.0
DISTVERSIONSUFFIX=-beta.4
CATEGORIES=	www

#DISTFILES=	electron-yarn-cache-${ELECTRON_VER}${EXTRACT_SUFX}:prefetch

MAINTAINER=	maintainer@email.com
COMMENT=	Signal desktop application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	Signal-Desktop
GH_ACCOUNT=	signalapp

USES=		desktop-file-utils gmake python:3.7 shebangfix

BUILD_DEPENDS=	zip:archivers/zip \
		yarn:www/yarn \
		vips>=8.10.5:graphics/vips \
#		npm-node${NODE_VER_MAJOR}>0:www/npm-node${NODE_VER_MAJOR} \
		yarn-node${NODE_VER_MAJOR}>0:www/yarn-node${NODE_VER_MAJOR} \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR}

RUN_DEPENDS=	npm:www/npm \
		node:www/node \
		yarn:www/yarn \
		yarn-node14>0:www/yarn-node14 \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR}

TEST_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		bash:shells/bash

#USE_LDCONFIG=	${DATADIR}

# Don't download electron binary distribution on electron node_modules installation
MAKE_ENV+=	ELECTRON_SKIP_BINARY_DOWNLOAD=1
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1
MAKE_ENV+=	NODE_DTRACE_PROVIDER_REQUIRE=hard

#post-patch:
	# force use of electron version matching port one
#	${REINPLACE_CMD} -E 's|^(target ").*(")$$|\1${ELECTRON_VER}\2|' \
#		${WRKSRC}/.yarnrc
	# setup yarnrc for using local node headers
#	${ECHO_CMD} 'nodedir "${LOCALBASE}/share/electron${ELECTRON_VER_MAJOR}/node_headers"' >> \
#		${WRKSRC}/.yarnrc
#	${ECHO_CMD} 'nodedir "${WRKDIR}/node-v${NODE_VER}"' >> \
#		${WRKSRC}/remote/.yarnrc
	# setup yarnrc for offline node_modules installation
#	${ECHO_CMD} 'yarn-offline-mirror "../yarn-offline-cache"' >> \
#		${WRKSRC}/.yarnrc
#	(cd ${WRKSRC} && \
#		${FIND} -E . -type f -iregex '${SHEBANG_REGEX}' \
#			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
#	(cd ${WRKSRC} && \
#		${FIND} ${PATHFIX_FILES} -type f \
#			-exec ${SED} -i '' -e "s|/usr/bin/pgrep|/bin/pgrep|g" {} ';')
#
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --fronze-lockfile --global yarn \
	&& ${BASH} yarn --verbose install \
	&& yarn --verbose grunt

#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
#		yarn --verbose grunt
#
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
#		yarn --verbose build-release --linux

#do-install:

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn test

.include <bsd.port.mk>

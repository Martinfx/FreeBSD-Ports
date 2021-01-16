# $FreeBSD$

PORTNAME=	Signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.39.5
CATEGORIES=	www

MAINTAINER=	maintainer@email.com
COMMENT=	Signal desktop application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	Signal-Desktop
GH_ACCOUNT=	signalapp

#BUILD_DEPENDS=	zip:archivers/zip \
#		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
#		npm:www/npm-node12   \
#		yarn:www/yarn-node10 \
#		vips:graphics/vips   \
#		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR}

BUILD_DEPENDS=	zip:archivers/zip \
		yarn:www/yarn \
		vips:graphics/vips \
#		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR}

RUN_DEPENDS=	npm:www/npm \
		node:www/node \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR}

USES=		desktop-file-utils gl gmake python:3.7
USE_GL=		gl

#NODE_VER=	13.3.0
#NODE_VER_MAJOR=	${NODE_VER:C/\..*$//}

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install  --global yarn
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install -g node-gyp

do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn add grunt icon-gen build:webpack
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn --verbose install
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn --verbose grunt
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} build:webpack

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn test

.include <bsd.port.mk>

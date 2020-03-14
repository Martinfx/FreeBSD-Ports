# $FreeBSD$

PORTNAME=	Signal-desktop
DISTVERSIONPREFIX=	v
DISTVERSION=	1.32.1
CATEGORIES=	www

MAINTAINER=	maintainer@email.com
COMMENT=	Signal desktop application

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_PROJECT=	Signal-Desktop
GH_ACCOUNT=	signalapp

BUILD_DEPENDS=	zip:archivers/zip \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR} \
		npm:www/npm-node12   \
		yarn:www/yarn-node10 \
		vips:graphics/vips   \
		${PYTHON_PKGNAMEPREFIX}xattr>0:devel/py-xattr@${PY_FLAVOR}

USES=		desktop-file-utils gl gmake python:2.7
USE_GL=		gl

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm install --global yarn

do-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn add grunt icon-gen build:webpack
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} yarn install --frozen-lockfile

do-test:
	${SH} yarn test



.include <bsd.port.mk>

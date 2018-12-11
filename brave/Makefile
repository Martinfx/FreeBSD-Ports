# $FreeBSD$

PORTNAME=	brave
PORTVERSION=	0.57.18
DISTVERSIONPREFIX=v
CATEGORIES=	www

MAINTAINER=	maintainer@email.com
COMMENT=	Safe browser

#LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FETCH_DEPENDS=	npm:www/npm

BUILD_DEPENDS=	libnotify>0:devel/libnotify \
		pkg-config:devel/pkgconf \
		python:lang/python \
		node:www/node \
		npm:www/npm \
		ninja:devel/ninja

RUN_DEPENDS=	bash:shells/bash \
		node:www/node

USES=		compiler:c++14-lang ninja pkgconfig python:2.7 \
		shebangfix tar:xz

USE_XORG=	x11 xcb xcomposite xcursor xext xdamage xfixes xi \
		xrandr xrender xscrnsaver xtst

NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	brave
GH_PROJECT=	brave-browser
GH_TUPLE=	yzgyyang:depot-tools:605dd31:depot_tools/vendor/depot_tools \
		pallets:jinja:209fd39:jinja2/vendor/jinja2 \
		brave:brave-core:57c6ce8:brave/src/brave
#		brave:tracking-protection:6b6faf7:brave/src/brave/vendor/tracking-protection \
#		brave:ad-block:dcfc584:brave/src/brave/vendor/ad-block \
#		brave:brave-extension:038a43a:brave/src/brave/vendor/brave-extension

post-fetch:
	${MKDIR} ${WRKDIR}/npm-precache
	${CP} ${FILESDIR}/package.json ${WRKDIR}/npm-precache
	${CP} ${FILESDIR}/package-lock.json ${WRKDIR}/npm-precache
	( cd ${WRKDIR}/npm-precache && npm install --verbose || true )
	( cd ${WRKDIR}/npm-precache && npm install --verbose)

#do-configure:
#	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} NODE_DTRACE_PROVIDER_REQUIRE=hard)
#	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} GIT_DISCOVERY_ACROSS_FILESYSTEM=yes)
#	(cd ${WRKSRC} && npm install --verbose)
#	(cd ${WRKSRC} && npm run init)
#	(cd ${WRKSRC} && ${BASH} git init)
#	(cd ${WRKSRC} && ${BASH} git submodule sync)
#	(cd ${WRKSRC} && ${BASH} git submodule update --init --recursive)

do-install:
	(cd ${WRKSRC} && ${BASH} git init)
	(cd ${WRKSRC} && ${BASH} npm install --verbose)
	(cd ${WRKSRC} && ${BASH} npm run init)

# GN generator bootstrapping and generating ninja files
#do-configure:
#	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CC=${CC} CXX=${CXX} LD=${CXX} \
#			READELF=${READELF} AR=${AR} NM=${NM} ${PYTHON_CMD} \
#			./tools/gn/bootstrap/bootstrap.py ${GN_BOOTSTRAP_FLAGS}

.include <bsd.port.mk>

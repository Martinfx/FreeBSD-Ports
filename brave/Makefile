PORTNAME=	brave
DISTVERSIONPREFIX=v
DISTVERSION=	1.75.155
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	safe browser

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		node:www/node

BUILD_DEPENDS=  libnotify>0:devel/libnotify \
                pkg-config:devel/pkgconf \
                python:lang/python \
                node:www/node \
                npm:www/npm \
                ninja:devel/ninja

USES=           compiler:c++14-lang python:3.11+ pkgconfig \
                nodejs:20 shebangfix

USE_GITHUB=     yes
GH_ACCOUNT=     brave
GH_PROJECT=     brave-browser
GH_TUPLE=       brave:brave-core:8d3cd1b:core/src/brave \
                brave:adblock-rust:fd4b7b3:adblock/src/brave/components/adblock_rust_ffi \
		brave:chromium:47e0e94:chromium \
		Martinfx:depot_tools:24d9ad6:depot/src/brave/vendor/depot_tools

#BINARY_ALIAS=	vpython3=${PYTHON_CMD}

#.include <bsd.port.options.mk>
#NO_ARCH=        yes
#NO_BUILD=       yes
do-configure:
#	cd ${WRKSRC}/src/brave && npm install --verbose
#	${CP} -vpR ${WRKDIR}/chromium-47e0e94/* ${WRKSRC}/src
	cd ${WRKSRC}/src/brave && npm run sync --  --target_os=linux --target_arch=x64 --gclient_verbose --force

#do-install:
	#cd ${WRKSRC}/src/brave && npm install --verbose
	#cd ${WRKSRC}/src/brave && npm run init -- --target_os=linux --target_arch=x64
#	cd ${WRKSRC}/src/brave && npm run build -- Release --target_os=linux --target_arch=x64 \
# 	--gn enable_dsyms:false --gn enable_stripping:false

.include <bsd.port.mk>

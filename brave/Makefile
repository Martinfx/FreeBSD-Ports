PORTNAME=       brave
DISTVERSIONPREFIX=v
DISTVERSION=    1.75.155
CATEGORIES=     www
MASTER_SITES=   https://github.com/chromium/chromium/archive/refs/tags/:chromium
DISTFILES=      134.0.6945.2${EXTRACT_SUFX}:chromium
EXTRACT_SUFX=   .tar.gz

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        safe browser

LICENSE=        MPL20
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=  libnotify>0:devel/libnotify \
                pkg-config:devel/pkgconf \
                python:lang/python \
                node:www/node \
                npm:www/npm \
                ninja:devel/ninja

USES=           compiler:c++14-lang pkgconfig \
                nodejs:22 shebangfix tar:xz

USE_GITHUB=     yes
GH_ACCOUNT=     brave
GH_PROJECT=     brave-browser
GH_TUPLE=       brave:brave-core:8d3cd1b:core/src/brave \
                brave:adblock-rust:fd4b7b3:adblock/src/brave/components/adblock_rust_ffi

NO_ARCH=        yes
NO_BUILD=       yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} npm run build


.include <bsd.port.mk>

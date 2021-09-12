PORTNAME=	wasm3
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	The fastest WebAssembly interpreter, and the most universal runtime.

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	wasm3
GH_PROJECT=	wasm3

PLIST_FILES=	wasm3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

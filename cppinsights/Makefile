PORTNAME=	cppinsights
DISTVERSIONPREFIX=	v_
DISTVERSION=	17.0
CATEGORIES=	sysutils

MAINTAINER=	maxfx@hades
COMMENT=	C++ Insights - See your source code with the eyes of a compiler.
WWW=		https://cppinsights.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake llvm:17

LIB_DEPENDS=	libLLVM-17.so:devel/llvm17

USE_GITHUB=	yes
GH_ACCOUNT=	andreasfertig
GH_PROJECT=	cppinsights

CMAKE_ARGS+=	-DLLVM_CONFIG_PATH="${LOCALBASE}/llvm17/bin/llvm-config"

.include <bsd.port.mk>

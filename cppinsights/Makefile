PORTNAME=	cppinsights
DISTVERSIONPREFIX=	v_
DISTVERSION=	17.0
CATEGORIES=	sysutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	C++ Insights - See your source code with the eyes of a compiler.
WWW=		https://github.com/andreasfertig/cppinsights

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake llvm:min=17,lib
USE_GITHUB=	yes
GH_ACCOUNT=	andreasfertig
GH_PROJECT=	cppinsights

CMAKE_ARGS=	-DLLVM_CONFIG_PATH="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config"

.include <bsd.port.mk>

PORTNAME=	clang-uml
DISTVERSION=	0.6.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Customizable automatic UML diagram generator for C++ based on Clang.
WWW=		https://github.com/bkryza/clang-uml

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	yaml-cpp>0:devel/yaml-cpp
LIB_DEPENDS=	libyaml-cpp.so:devel/yaml-cpp

USES=		cmake llvm:min=18,lib
USE_GITHUB=	yes

GH_ACCOUNT=	bkryza
GH_PROJECT=	clang-uml

CMAKE_ARGS=	-DLLVM_CONFIG_PATH="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config"

.include <bsd.port.mk>

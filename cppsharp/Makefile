]PORTNAME=	cppsharp
DISTVERSIONPREFIX=v
DISTVERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	cpp binding to C#

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	premake5>0:devel/premake5

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_PROJECT=	CppSharp
GH_TAG=		3f923b1c640307fc19f0c83902c81bde1dc50b3a

do-configure:
	@cd ${WRKSRC} && build/build.sh clone_llvm
	@cd ${WRKSRC} && build/build.sh build_llvm

.include <bsd.port.mk>

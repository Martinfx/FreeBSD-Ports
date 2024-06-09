]PORTNAME=	cppsharp
DISTVERSIONPREFIX=v
DISTVERSION=	1.1.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	cpp binding to C#

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	premake5>0:devel/premake5

USES=		ninja
USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_PROJECT=	CppSharp
GH_TAG=		3f923b1c640307fc19f0c83902c81bde1dc50b3a

do-fetch:
	fetch https://github.com/llvm/llvm-project/archive/6eb36aed86ea276695697093eb8136554c29286b.tar.gz
#	mv 6eb36aed86ea276695697093eb8136554c29286b.tar.gz ${WRKSRC}/build/llvm
do-configure:
#	@cd ${WRKSRC} && build/build.sh clone_llvm
	mv 6eb36aed86ea276695697093eb8136554c29286b.tar.gz ${WRKSRC}/build/llvm
	@cd ${WRKSRC} && build/build.sh build_llvm

	@chmod +x ${WRKSRC}/build/generate.sh
	@cd ${WRKSRC} && build/generate.sh
do+build: 
	@cd ${WRKSRC} && build/build.sh

.include <bsd.port.mk>

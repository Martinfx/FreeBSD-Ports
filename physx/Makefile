PORTNAME=	physx
DISTVERSION=	4.0.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	NVIDIA PhysX SDK

LICENSE=	NVIDIA
LICENSE_NAME=	NVIDIA PhysX SDK 4.1
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=  dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIAGameWorks
GH_PROJECT=	PhysX
GH_TAGNAME=	a2c0428

do-build:
	@cd ${WRKSRC}/physx && ${BASH} ./generate_projects.sh
	@cd ${WRKSRC}/physx/compiler/freebsd-release && gmake

do-install:
	@cd ${WRKSRC}/physx/bin/freebsd.clang/release/ && ${INSTALL_LIB} *.so ${STAGEDIR}${PREFIX}/lib
        @cd ${WRKSRC}/physx/bin/freebsd.clang/release/ && ${INSTALL_LIB} *.a ${STAGEDIR}${PREFIX}/lib


.include <bsd.port.mk>

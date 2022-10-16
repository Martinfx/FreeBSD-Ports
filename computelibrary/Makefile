PORTNAME=	ComputeLibrary
DISTVERSIONPREFIX=v
DISTVERSION=	22.08
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	arm compute library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=           scons
USE_GCC=	yes
USE_GITHUB=     yes
GH_ACCOUNT=     ARM-software
GH_PROJECT=     ComputeLibrary

MAKE_ARGS+=	os=freebsd Werror=0 neon=0 opencl=0 embed_kernels=0 examples=0 arch=x86 build=native

.include <bsd.port.mk>

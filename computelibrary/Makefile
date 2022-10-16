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

SCONS_ARGS+=	os="freebsd" Werror=0 neon=1 opencl=0 embed_kernels=0 examples=0 arch=armv-8a build=native
MAKE_ARGS+=	CC="${CC}"
MAKE_ARGS+=	CXX="${CXX}"
MAKE_ARGS+=	CXXFLAGS="${CXXFLAGS} -fPIC"


.include <bsd.port.pre.mk>

MAKE_ARGS=	${SCONS_ARGS}

.include <bsd.port.post.mk>

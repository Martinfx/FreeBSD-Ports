PORTNAME=	ComputeLibrary
DISTVERSIONPREFIX=v
DISTVERSION=	23.02
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Arm compute library
WWW=		https://github.com/ARM-software/ComputeLibrary

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		scons
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	ComputeLibrary

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
SCONS_ARGS+=	os=freebsd Werror=0 neon=0 opencl=1 embed_kernels=0 examples=1 arch=x86_64 build=native
.elif ${ARCH} == "aarch64"
SCONS_ARGS+=	os=freebsd Werror=0 neon=1 opencl=0 embed_kernels=0 examples=0 arch=arm64-v8a build=native
.elif ${ARCH} == "armv7"
SCONS_ARGS+=	os=freebsd Werror=0 neon=1 opencl=0 embed_kernels=0 examples=0 arch=armv7a build=native
.endif

MAKE_ARGS=	${SCONS_ARGS}

do-install:
	${INSTALL_LIB} ${WRKSRC}/build/*.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/build/*.a ${STAGEDIR}${PREFIX}/lib/
	${CP} -R ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.post.mk>

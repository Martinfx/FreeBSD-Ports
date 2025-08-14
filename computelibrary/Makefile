PORTNAME=	ComputeLibrary
DISTVERSIONPREFIX=v
DISTVERSION=	52.3.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Arm compute library
WWW=		https://github.com/ARM-software/ComputeLibrary

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSES/MIT.txt

ONLY_FOR_ARCHS=	aarch64 amd64 armv7

USES=		scons
#USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ARM-software
GH_PROJECT=	ComputeLibrary
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

SCONS_ARGS_amd64=	neon=0 opencl=1 examples=1 arch=x86_64
SCONS_ARGS_aarch64=	neon=1 opencl=0 examples=0 arch=arm64-v8a
SCONS_ARGS_armv7=	neon=1 opencl=0 examples=0 arch=armv7a
SCONS_ARGS+= 		os=freebsd Werror=0 embed_kernels=0 build=native ${SCONS_ARGS_${ARCH}}
MAKE_ARGS=	${SCONS_ARGS}

do-install:
.for dir in arm_compute support utils
	${CP} -vR ${WRKSRC}/${dir} ${STAGEDIR}${PREFIX}/include
.endfor
	${INSTALL_DATA}	${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/build/libarm_compute.so \
                ${STAGEDIR}${PREFIX}/lib/libarm_compute.so
	${INSTALL_DATA} ${WRKSRC}/build/libarm_compute_graph.so \
                ${STAGEDIR}${PREFIX}/lib/libarm_compute_graph.so
	${INSTALL_DATA} ${WRKSRC}/build/*.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.post.mk>

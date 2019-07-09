# $FreeBSD$

PORTNAME=	halide
DISTVERSIONPREFIX=release_
DISTVERSION=	2019_08_27
CATEGORIES=	lang
DISTNAME=	2019_08_27

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Halide a language for fast and portable data-parallel computation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake ninja compiler:c++17-lang

USE_GITHUB=	yes
GH_ACCOUNT=	halide
GH_PROJECT=	Halide
GH_TAGNAME=	de12425a

BUILD_DEPENDS=  llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

CMAKE_ARGS=     -DCMAKE_BUILD_TYPE=Release \
		-DLLVM_DIR=${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/cmake/llvm \
		-DWITH_APPS=OFF      \
		-DWITH_TUTORIALS=OFF \
		-DWITH_DOCS=OFF      \
		-DHALIDE_SHARED_LIBRARY=OFF

PLIST_FILES=	lib/libHalide.a				\
		include/Halide.h			\
		include/HalideBuffer.h			\
		include/HalideRuntime.h			\
		include/HalideRuntimeCuda.h		\
		include/HalideRuntimeHexagonHost.h	\
		include/HalideRuntimeMetal.h		\
		include/HalideRuntimeOpenCL.h		\
		include/HalideRuntimeOpenGL.h		\
		include/HalideRuntimeOpenGLCompute.h	\
		include/HalideRuntimeQurt.h

.include <bsd.port.mk>

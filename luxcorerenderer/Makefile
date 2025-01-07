PORTNAME=	luxcorerender
DISTVERSIONPREFIX=luxcorerender-v
DISTVERSION=	2.9alpha2
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/lastrodamo/LuxCoreRender/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	LuxCore renderer
WWW=		https://luxcorerender.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	boost-libs>=1.85.0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		c-blosc>0:archivers/c-blosc \
		doxygen>0:devel/doxygen \
		harfbuzz>0:print/harfbuzz \
		openimageio>0:graphics/openimageio \
		opensubdiv>0:graphics/opensubdiv \
		opencolorio>0:graphics/opencolorio \
		oidn>0:graphics/oidn \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		openvdb>0:misc/openvdb \
		opencl>0:devel/opencl \
		pocl>0:lang/pocl \
		gtk3>0:x11-toolkits/gtk30 \
		embree>0:graphics/embree \
		eigen>0:math/eigen3 \
		nlohmann-json>0:devel/nlohmann-json \
		stb>0:devel/stb

LIB_DEPENDS=	libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		bison cmake python:3.11+ pkgconfig localbase
USE_GCC=	yes
USE_GNOME=	cairo pango glib20 gtk30
CMAKE_OFF=	LUXCORE_DISABLE_OIDN LUXRAYS_DISABLE_OPENCL WIN_BUILD_DEMOS
CMAKE_ON=	LUXRAYS_DISABLE_CUDA
CMAKE_ARGS=	-DOIDN_CORE_LIBRARY:STRING=${LOCALBASE}/lib
#PIE_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.if !exists(/usr/include/omp.h)
LDFLAGS+=	-fopenmp
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>

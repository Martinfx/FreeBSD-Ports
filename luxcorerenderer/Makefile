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
		openimageio>0:graphics/openimageio \
		opensubdiv>0:graphics/opensubdiv \
		oidn>0:graphics/oidn \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		embree>0:graphics/embree

LIB_DEPENDS=	libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		bison cmake python:3.11+ localbase

CMAKE_OFF=	LUXCORE_DISABLE_OIDN LUXRAYS_DISABLE_OPENCL
CMAKE_ON=	LUXRAYS_DISABLE_CUDA
CMAKE_ARGS=	-DOIDN_CORE_LIBRARY:STRING=${LOCALBASE}/lib
#PIE_UNSAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>

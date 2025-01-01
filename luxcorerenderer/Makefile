PORTNAME=	luxcorerenderer
DISTVERSIONPREFIX=luxcorerender-v
DISTVERSION=	2.9alpha1
CATEGORIES=	devel
MAINTAINER=	freebsd@sysctl.cz
COMMENT=	LuxCore renderer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		c-blosc>0:archivers/c-blosc \
		openimageio>0:graphics/openimageio \
		oidn>0:graphics/oidn \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		embree>0:graphics/embree

LIB_DEPENDS=	libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs

USES=		bison cmake python localbase
USE_GITHUB=	yes
GH_ACCOUNT=	LuxCoreRender
GH_PROJECT=	LuxCore

CMAKE_OFF=	LUXRAYS_DISABLE_OPENCL LUXCORE_DISABLE_OIDN
CMAKE_ARGS=	-DOIDN_CORE_LIBRARY:STRING=${LOCALBASE}/lib

.include <bsd.port.mk>

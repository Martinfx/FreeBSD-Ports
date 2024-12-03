PORTNAME=	gaffer
DISTVERSION=	1.5.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Gaffer is a node-based application \
		for lookdev, lighting and automation.
WWW=		http://www.gafferhq.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  bitstream-vera>0:x11-fonts/bitstream-vera \
		c-blosc2>0:archivers/c-blosc2 \
		cortex>0:graphics/cortex \
		cycles>0:graphics/cycles \
		cmark>0:textproc/cmark \
		expat>0:textproc/expat2 \
		freetype2>0:print/freetype2 \
		glew>0:graphics/glew \
		hdf5>0:science/hdf5 \
		libfmt>0:devel/libfmt \
		inkscape:graphics/inkscape \
		Imath>0:math/Imath \
		boost-libs>=1.85.0:devel/boost-libs \
		openexr>0:graphics/openexr \
		openshadinglanguage>0:graphics/openshadinglanguage \
		embree>0:graphics/embree

USES=		python:3.11 localbase scons qt:5

USE_QT=		core
USE_GITHUB=	yes
GH_ACCOUNT=	GafferHQ
GH_PROJECT=	gaffer

SCONS_ARGS=	LOCATE_DEPENDENCY_LIBPATH=${LOCALBASE}/lib
SCONS_ARGS+=	LOCATE_DEPENDENCY_SYSTEMPATH=${LOCALBASE}/include
SCONS_ARGS+=	BOOST_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	BOOST_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BOOST_LIB_SUFFIX=""
SCONS_ARGS+= 	SPHINX=${LOCALBASE}/bin/sphinx-build
SCONS_ARGS+=	WARNINGS_AS_ERRORS=0
SCONS_ARGS+=	PYTHON=${PYTHON_CMD}
SCONS_ARGS+=	CXX=${CXX}
#SCONS_ARGS+=	CYCLES_ROOT=${LOCALBASE}/bin/cycles

.include <bsd.port.pre.mk>
MAKE_ARGS=	${SCONS_ARGS}
.include <bsd.port.post.mk>
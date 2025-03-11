PORTNAME=	cortex
DISTVERSION=	10.5.13.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Libraries for visual effects software development.
WWW=		https://github.com/ImageEngine/cortex

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alembic>0:graphics/alembic \
		boost-libs>=1.87.0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>=1.87.0:devel/boost-python-libs@${PY_FLAVOR} \
		pybind11>0:devel/pybind11 \
		c-blosc>0:archivers/c-blosc \
		doxygen>0:devel/doxygen \
		onetbb>0:devel/onetbb \
		freetype2>0:print/freetype2 \
		glew>0:graphics/glew \
		openexr>0:graphics/openexr \
		openimageio>0:graphics/openimageio \
		openvdb>0:misc/openvdb

LIB_DEPENDS+=	libboost_filesystem.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_timer.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs \
		libOpenEXR-3_3.so:graphics/openexr \
		libtbb.so:devel/onetbb \
		libblosc.so:archivers/c-blosc \
		libIex-3_3.so:graphics/openexr \
		libImath-3_1.so:math/Imath \
		libIlmThread-3_3.so:graphics/openexr \
		libhdf5.so:science/hdf5 \
		libAlembic.so:graphics/alembic \
		libfreetype.so:print/freetype2 \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb

USES=		python:3.11+ localbase gettext-runtime scons
USE_GL=		glew glu gl
USE_GITHUB=	yes
GH_ACCOUNT=	ImageEngine
GH_PROJECT=	cortex

# setup variables for compilation
SCONS_ARGS+=	BOOST_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	BOOST_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BOOST_LIB_SUFFIX=""
SCONS_ARGS+=	OPENEXR_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	OPENEXR_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	FREETYPE_INCLUDE_PATH=${LOCALBASE}/include/freetype2
SCONS_ARGS+=	FREETYPE_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	BLOSC_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	BLOSC_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	OIIO_INCLUDE_PATH=${LOCALBASE}/include/OpenImageIO
SCONS_ARGS+=	OIIO_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	TBB_INCLUDE_PATH=${LOCALBASE}/include/oneapi/
SCONS_ARGS+=	TBB_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	VDB_INCLUDE_PATH=${LOCALBASE}/include/openvdb
SCONS_ARGS+=	VDB_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	ALEMBIC_INCLUDE_PATH=${LOCALBASE}/include/Alembic
SCONS_ARGS+=	ALEMBIC_LIB_PATH=${LOCALBASE}/lib
SCONS_ARGS+=	PYBIND11_INCLUDE_PATH=${LOCALBASE}/include
SCONS_ARGS+=	WITH_GL=1
SCONS_ARGS+=	WARNINGS_AS_ERRORS=0
SCONS_ARGS+=	PYTHON_CONFIG=${PYTHON_CMD}-config
SCONS_ARGS+=	PYTHON=${PYTHON_CMD}
SCONS_ARGS+=	CXX=${CXX}
SCONS_ARGS+=	INSTALL_PREFIX=${STAGEDIR}${PREFIX}
SCONS_ARGS+=	INSTALL_HEADER_DIR=${STAGEDIR}${PREFIX}/include

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/*.so ${STAGEDIR}${PREFIX}/lib/
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.h")
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.inl")
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	(cd ${WRKSRC}/python && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})

.include <bsd.port.pre.mk>
MAKE_ARGS=	${SCONS_ARGS}
.include <bsd.port.post.mk>

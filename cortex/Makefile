PORTNAME=	cortex
DISTVERSION=	10.6.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Libraries for visual effects software development
WWW=		https://github.com/ImageEngine/cortex/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11

LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libblosc.so:archivers/c-blosc \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_timer.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libIex.so:graphics/openexr \
		libIlmThread.so:graphics/openexr \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/onetbb

USES=		gettext-runtime gl python:3.11+ scons
USE_GITHUB=	yes
GH_ACCOUNT=	ImageEngine
USE_GL=		gl glew glu
USE_LDCONFIG=	yes

SCONS_ARGS=	BOOST_INCLUDE_PATH=${LOCALBASE}/include \
		BOOST_LIB_PATH=${LOCALBASE}/lib \
		BOOST_LIB_SUFFIX="" \
		OPENEXR_INCLUDE_PATH=${LOCALBASE}/include \
		OPENEXR_LIB_PATH=${LOCALBASE}/lib \
		ILMBASE_INCLUDE_PATH=${LOCALBASE}/include \
		ILMBASE_LIB_PATH=${LOCALBASE}/lib \
		FREETYPE_INCLUDE_PATH=${LOCALBASE}/include/freetype2 \
		FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		BLOSC_INCLUDE_PATH=${LOCALBASE}/include \
		BLOSC_LIB_PATH=${LOCALBASE}/lib \
		OIIO_INCLUDE_PATH=${LOCALBASE}/include/OpenImageIO \
		OIIO_LIB_PATH=${LOCALBASE}/lib \
		TBB_INCLUDE_PATH=${LOCALBASE}/include/oneapi/ \
		TBB_LIB_PATH=${LOCALBASE}/lib \
		VDB_INCLUDE_PATH=${LOCALBASE}/include/openvdb \
		VDB_LIB_PATH=${LOCALBASE}/lib \
		ALEMBIC_INCLUDE_PATH=${LOCALBASE}/include/Alembic \
		ALEMBIC_LIB_PATH=${LOCALBASE}/lib \
		PYBIND11_INCLUDE_PATH=${LOCALBASE}/include \
		USD_INCLUDE_PATH=${LOCALBASE}/include/pxr \
		USD_LIB_PATH=${LOCALBASE}/lib \
		USD_LIB_PREFIX="libusd_" \
		WITH_GL=1 WARNINGS_AS_ERRORS=0 \
		PYTHON_CONFIG=${PYTHON_CMD}-config \
		PYTHON=${PYTHON_CMD} \
		CXX=${CXX} DOXYGEN=no \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		INSTALL_HEADER_DIR=${STAGEDIR}${PREFIX}/include

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/*.so ${STAGEDIR}${PREFIX}/lib/
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.h")
	(cd ${WRKSRC}/include && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.inl")
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	(cd ${WRKSRC}/python && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/IECore*/*.so

do-test:
# for run tests need install idebug python library
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} scons test ${SCONS_ARGS}

.include <bsd.port.pre.mk>

MAKE_ARGS=	${SCONS_ARGS}

.include <bsd.port.post.mk>


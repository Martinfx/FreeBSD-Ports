PORTNAME=	cortex
DISTVERSION=	10.7.1.3
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Libraries for visual effects software development
WWW=		https://github.com/ImageEngine/cortex/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		nanobind>0:devel/nanobind \
		robin-map>0:devel/robin-map

LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libblosc.so:archivers/c-blosc \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_timer.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libhdf5.so:science/hdf5 \
		libIex.so:graphics/openexr \
		libIlmThread.so:graphics/openexr \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/onetbb \
		libusd_ms.so:graphics/openusd

USES=		compiler:c++17-lang gettext-runtime gl pkgconfig python scons xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ImageEngine
USE_GL=		gl glew glu
USE_LDCONFIG=	yes
USE_XORG=	x11

SCONS_ARGS=	BOOST_INCLUDE_PATH=${LOCALBASE}/include \
		BOOST_LIB_PATH=${LOCALBASE}/lib \
		BOOST_LIB_SUFFIX="" \
		OPENEXR_INCLUDE_PATH=${LOCALBASE}/include \
		OPENEXR_LIB_PATH=${LOCALBASE}/lib \
		ILMBASE_INCLUDE_PATH=${LOCALBASE}/include \
		ILMBASE_LIB_PATH=${LOCALBASE}/lib \
		FREETYPE_INCLUDE_PATH=${LOCALBASE}/include/freetype2 \
		FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		GLEW_INCLUDE_PATH=${LOCALBASE}/include \
		GLEW_LIB_PATH=${LOCALBASE}/lib \
		HDF5_INCLUDE_PATH=${LOCALBASE}/include \
		HDF5_LIB_PATH=${LOCALBASE}/lib \
		PYTHON_INCLUDE_PATH=${PYTHON_INCLUDEDIR} \
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
		NANOBIND_INCLUDE_PATH=${LOCALBASE}/include \
		NANOBIND_SRC_PATH=${LOCALBASE}/share/nanobind/src \
		USD_INCLUDE_PATH=${LOCALBASE}/include \
		USD_LIB_PATH=${LOCALBASE}/lib \
		WITH_GL=1 WARNINGS_AS_ERRORS=0 \
		PYTHON_CONFIG=${PYTHON_CMD}-config \
		PYTHON=${PYTHON_CMD} \
		CXX=${CXX} DOXYGEN=no \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		INSTALL_HEADER_DIR=${STAGEDIR}${PREFIX}/include \
		INSTALL_GLSL_HEADER_DIR=${STAGEDIR}${DATADIR} \
		INSTALL_GLSL_SHADER_DIR=${STAGEDIR}${DATADIR} \
		INSTALL_PYTHON_DIR=${STAGEDIR}${PYTHON_SITELIBDIR} \
		INSTALL_PKG_CONFIG_FILE=0 \
		INSTALL_IECORE_OPS="" \
		WITH_USD_MONOLITHIC=1

# These are the suites `scons test` would run, listed by directory rather than
# by scons alias because the aliases only exist for the modules which were
# built. IECoreGL needs a real OpenGL context, so it is only run when a display
# is available. The IECoreUSD and IECoreAlembic suites live under contrib and
# are not part of `scons test` at all.
TEST_SUITES=	test/IECore \
		test/IECoreScene \
		test/IECoreImage
.if defined(DISPLAY)
TEST_SUITES+=	test/IECoreGL
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libIECore*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/IECore*/_IECore*.so

do-test:
# for run tests need install idebug python library
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${SCONS} ${_MAKE_JOBS} \
		${TEST_SUITES} ${SCONS_ARGS}

.include <bsd.port.pre.mk>

MAKE_ARGS=	${SCONS_ARGS}

.include <bsd.port.post.mk>


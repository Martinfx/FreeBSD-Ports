PORTNAME=	cortex
DISTVERSION=	10.7.1.3
CATEGORIES=	graphics devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Open source libraries for visual effects software development
WWW=		https://github.com/ImageEngine/cortex

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	depends on graphics/openusd

BUILD_DEPENDS=	${LOCALBASE}/include/nanobind/nanobind.h:devel/nanobind \
		${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map
LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libblosc.so:archivers/c-blosc \
		libboost_iostreams.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libfreetype.so:print/freetype2 \
		libGLEW.so:graphics/glew \
		libImath.so:math/Imath \
		libOpenEXR.so:graphics/openexr \
		libOpenImageIO.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/onetbb \
		libusd_ms.so:graphics/openusd \
		${PY_BOOST}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/imath.so:math/Imath \
		${PYTHON_PKGNAMEPREFIX}openvdb>0:misc/py-openvdb@${PY_FLAVOR}

USES=		compiler:c++17-lang gl python scons xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ImageEngine
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	x11

SUB_FILES=	cortex.options
SUB_LIST=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		PYTHON_CMD="${PYTHON_CMD}" \
		STAGEDIR="${STAGEDIR}" \
		WRKDIR="${WRKDIR}"

# USES=scons passes CXXFLAGS and LINKFLAGS as single strings, which the
# SConstruct turns into a single (invalid) compiler argument, so all build
# settings are passed through an options file instead.
CORTEX_SCONS=	${SETENV} ${MAKE_ENV} ${SCONS} ${_MAKE_JOBS} \
		OPTIONS=${WRKDIR}/cortex.options

do-build:
# Cortex links its OpenVDB Python bindings against nanobind-static, which
# must use the same nanobind as misc/py-openvdb.
	@${MKDIR} ${WRKDIR}/nanobind
	cd ${WRKDIR}/nanobind && ${CXX} ${CXXFLAGS} -std=c++17 -fPIC \
		-fvisibility=hidden -fno-strict-aliasing -ffunction-sections \
		-fdata-sections -DNDEBUG -DNB_COMPACT_ASSERTIONS \
		-I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR} \
		-c ${LOCALBASE}/share/nanobind/src/nb_combined.cpp \
		-o nb_combined.o && ${AR} rcs libnanobind-static.a nb_combined.o
	@cd ${WRKSRC} && ${CORTEX_SCONS}

do-install:
	@cd ${WRKSRC} && ${CORTEX_SCONS} ${INSTALL_TARGET}
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata
	${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig ${STAGEDIR}${PREFIX}/libdata
	${REINPLACE_CMD} -e 's|${STAGEDIR}||g' \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/cortex.pc
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/cortex.pc.bak
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libIECore*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/IECore*/_IECore*.so
	${PYTHON_CMD} -m compileall -q -d ${PYTHON_SITELIBDIR} \
		${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>

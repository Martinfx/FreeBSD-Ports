PORTNAME=	cycles
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cycles is a physically based production renderer developed by Blender.
WWW=		https://github.com/blender/cycles

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alembic>0:graphics/alembic \
		boost-libs>=1.85.0:devel/boost-libs \
		libepoxy>0:graphics/libepoxy \
		oidn>0:graphics/oidn \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		openimageio>0:graphics/openimageio \
		openjpeg>0:graphics/openjpeg \
		openpgl>0:graphics/openpgl \
		openshadinglanguage>0:graphics/openshadinglanguage \
		opensubdiv>0:graphics/opensubdiv \
		openvdb>0:misc/openvdb \
		webp>0:graphics/webp \
		zstd>0:archivers/zstd

LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libboost_atomic.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_wave.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libIex.so:graphics/openexr \
		libIlmThread.so:graphics/openexr \
		libImath.so:math/Imath \
		libminizip.so:archivers/minizip \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libOpenEXRCore.so:graphics/openexr \
		libOpenImageDenoise.so:graphics/oidn \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libopenjp2.so:graphics/openjpeg \
		libopenvdb.so:misc/openvdb \
		libosdCPU.so:graphics/opensubdiv \
		libosdGPU.so:graphics/opensubdiv \
		liboslcomp.so:graphics/openshadinglanguage \
		liboslexec.so:graphics/openshadinglanguage \
		liboslnoise.so:graphics/openshadinglanguage \
		liboslquery.so:graphics/openshadinglanguage \
		libpng16.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libpystring.so:devel/pystring \
		libpython3.11.so:lang/python311 \
		libtbb.so:devel/onetbb \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		cmake:testing jpeg
USE_GITHUB=	yes
GH_ACCOUNT=	blender
GH_PROJECT=	cycles

CMAKE_ARGS=	-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"

CMAKE_ON=	CMAKE_POSITION_INDEPENDENT_CODE WITH_CYCLES_ALEMBIC \
		WITH_CYCLES_DEVICE_ONEAPI WITH_CYCLES_LOGGING \
		WITH_CYCLES_OPENCOLORIO WITH_CYCLES_OPENIMAGEDENOISE \
		WITH_CYCLES_OPENSUBDIV WITH_CYCLES_OPENVDB WITH_CYCLES_OSL
CMAKE_OFF=	WITH_CYCLES_DEVICE_OPTIX WITH_CYCLES_NANOVDB WITH_CYCLES_USD \
		WITH_LIBS_PRECOMPILED

OPTIONS_DEFINE=		EMBREE
EMBREE_DESC=		Collection of high-performance ray tracing kernels.
EMBREE_BUILD_DEPENDS=	embree>0:graphics/embree
EMBREE_LIB_DEPENDS=	libembree3.so:graphics/embree
EMBREE_CMAKE_BOOL=	WITH_CYCLES_EMBREE
OPTIONS_EXCLUDE=	EMBREE
OPTIONS_EXCLUDE_amd64=	EMBREE
OPTIONS_DEFAULT=	EMBREE
OPTIONS_SUB=		no

post-patch:
	@${REINPLACE_CMD} -e 's|%%BUILD_WRKSRC%%|${BUILD_WRKSRC}|g' \
		${WRKSRC}/src/app/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/cycles ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/app/opengl
	(cd ${WRKSRC}/src/app/opengl && ${COPYTREE_SHARE} "*.h" ${STAGEDIR}${PREFIX}/include/app/opengl)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device
	(cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} device ${STAGEDIR}${PREFIX}/include/ "-name *.h")
	${MKDIR} ${STAGEDIR}${PREFIX}/include/
	(cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.h" )
	${MKDIR} ${STAGEDIR}${PREFIX}/include/third_party/atomic
	(cd ${WRKSRC}/third_party/atomic/ && ${COPYTREE_SHARE} *.h ${STAGEDIR}${PREFIX}/include/third_party/atomic/)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/third_party/atomic/intern
	(cd ${WRKSRC}/third_party/atomic/intern && ${COPYTREE_SHARE} "*.h" ${STAGEDIR}${PREFIX}/include/third_party/atomic/intern)

.include <bsd.port.mk>


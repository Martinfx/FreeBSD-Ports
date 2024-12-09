PORTNAME=	cycles
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cycles is a physically based production renderer.
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
		opensycl>0:lang/opensycl \
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
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_wave.so:devel/boost-libs \
		libembree3.so:graphics/embree \
		libexpat.so:textproc/expat2 \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libIex-3_3.so:graphics/openexr \
		libIlmThread-3_3.so:graphics/openexr \
		libImath-3_1.so:math/Imath \
		libminizip.so:archivers/minizip \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR-3_3.so:graphics/openexr \
		libOpenEXRCore-3_3.so:graphics/openexr \
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

CMAKE_ARGS+=	-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders" \
		-DSYCL_LIBRARY="${LOCALBASE}/lib"
CMAKE_ON=	CMAKE_POSITION_INDEPENDENT_CODE WITH_CYCLES_ALEMBIC \
		WITH_CYCLES_DEVICE_ONEAPI \
		WITH_CYCLES_LOGGING WITH_CYCLES_OPENCOLORIO \
		WITH_CYCLES_OPENIMAGEDENOISE WITH_CYCLES_OPENSUBDIV \
		WITH_CYCLES_OPENVDB WITH_CYCLES_OSL
CMAKE_OFF=	WITH_CYCLES_DEVICE_OPTIX \
		WITH_CYCLES_NANOVDB \
		WITH_LIBS_PRECOMPILED \
		WITH_CYCLES_USD # dependent tbb-2020.3_4

OPTIONS_DEFINE=	EMBREE
EMBREE_DESC=		Collection of high-performance ray tracing kernels.
EMBREE_BUILD_DEPENDS=	embree>0:graphics/embree
EMBREE_CMAKE_BOOL=	WITH_CYCLES_EMBREE
OPTIONS_EXCLUDE=	EMBREE
OPTIONS_EXCLUDE_amd64=	EMBREE
OPTIONS_DEFAULT=	EMBREE
OPTIONS_SUB=		no

PLIST_FILES=	bin/cycles

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/cycles ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
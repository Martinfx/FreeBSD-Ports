PORTNAME=	cycles
DISTVERSIONPREFIX=v
DISTVERSION=	4.2.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	The Cycles Render Engine.
WWW=		https://github.com/blender/cycles

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	alembic>0:graphics/alembic \
		boost-libs>=1.85.0:devel/boost-libs \
		embree>0:graphics/embree \
		libepoxy>0:graphics/libepoxy \
		oidn>0:graphics/oidn \
		openjpeg>0:graphics/openjpeg \
		openimageio>0:graphics/openimageio \
		openexr>0:graphics/openexr \
		openshadinglanguage>0:graphics/openshadinglanguage \
		onetbb>0:devel/onetbb \
		opensubdiv>0:graphics/opensubdiv \
		openpgl>0:graphics/openpgl \
		openvdb>0:misc/openvdb \
		webp>0:graphics/webp \
		zstd>0:archivers/zstd

LIB_DEPENDS=	libAlembic.so:graphics/alembic \
		libglog.so:devel/glog \
		libgflags.so:devel/gflags\
		liboslcomp.so:graphics/openshadinglanguage \
		liboslexec.so:graphics/openshadinglanguage \
		liboslquery.so:graphics/openshadinglanguage \
		liboslnoise.so:graphics/openshadinglanguage \
		libembree3.so:graphics/embree \
		libosdGPU.so:graphics/opensubdiv \
		libosdCPU.so:graphics/opensubdiv \
		libOpenColorIO.so:graphics/opencolorio \
		libyaml-cpp.so:devel/yaml-cpp \
		libexpat.so:textproc/expat2 \
		libpystring.so:devel/pystring \
		libminizip.so:archivers/minizip \
		libopenvdb.so:misc/openvdb \
		libOpenImageDenoise.so:graphics/oidn \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libpng16.so:graphics/png \
		libopenjp2.so:graphics/openjpeg \
		libIex-3_3.so:graphics/openexr \
		libOpenEXR-3_3.so:graphics/openexr \
		libOpenEXRCore-3_3.so:graphics/openexr \
		libIlmThread-3_3.so:graphics/openexr \
		libImath-3_1.so:math/Imath \
		libpugixml.so:textproc/pugixml \
		libboost_iostreams.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_wave.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_atomic.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libpython3.11.so:lang/python311 \
		libtbb.so:devel/onetbb \
		libzstd.so:archivers/zstd

USES=		cmake jpeg
USE_GITHUB=	yes
GH_ACCOUNT=	blender
GH_PROJECT=	cycles

CMAKE_ARGS+=	-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"
CMAKE_ON=	WITH_CYCLES_ALEMBIC \
		WITH_CYCLES_EMBREE \
		WITH_CYCLES_LOGGING  \
		WITH_CYCLES_OPENCOLORIO \
		WITH_CYCLES_OPENIMAGEDENOISE \
		WITH_CYCLES_OPENSUBDIV \
		WITH_CYCLES_OPENVDB \
		WITH_CYCLES_OSL \
		CMAKE_POSITION_INDEPENDENT_CODE \
		WITH_CYCLES_DEVICE_ONEAPI
CMAKE_OFF=	WITH_LIBS_PRECOMPILED \
		WITH_CYCLES_NANOVDB \
		WITH_CYCLES_USD # dependent tbb-2020.3_4

PLIST_FILES=	bin/cycles

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.build/bin/cycles ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

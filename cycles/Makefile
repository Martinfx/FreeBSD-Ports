PORTNAME=	cycles
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.0
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

CMAKE_ARGS+=	-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"
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

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/cycles ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/include/app/opengl
	(cd ${WRKSRC}/src/app/opengl && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/app/opengl)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/bvh
	(cd ${WRKSRC}/src/bvh && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/bvh)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device
	(cd ${WRKSRC}/src/device && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/cpu
	(cd ${WRKSRC}/src/device/cpu && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/cpu)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/cuda
	(cd ${WRKSRC}/src/device/cuda && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/cuda)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/dummy
	(cd ${WRKSRC}/src/device/dummy && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/dummy)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/hip
	(cd ${WRKSRC}/src/device/hip && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/hip)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/hiprt
	(cd ${WRKSRC}/src/device/hiprt && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/hiprt)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/metal
	(cd ${WRKSRC}/src/device/metal && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/metal)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/multi
	(cd ${WRKSRC}/src/device/multi && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/multi)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/oneapi
	(cd ${WRKSRC}/src/device/oneapi && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/oneapi)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device/optix
	(cd ${WRKSRC}/src/device/optix && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/device/optix)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/graph
	(cd ${WRKSRC}/src/graph && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/graph)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hydra
	(cd ${WRKSRC}/src/hydra && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/hydra)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel
	(cd ${WRKSRC}/src/kernel && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/bake
	(cd ${WRKSRC}/src/kernel/bake && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/bake)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/bvh
	(cd ${WRKSRC}/src/kernel/bvh && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/bvh)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/camera
	(cd ${WRKSRC}/src/kernel/camera && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/camera)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/closure
	(cd ${WRKSRC}/src/kernel/closure && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/closure)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/cpu
	(cd ${WRKSRC}/src/kernel/device/cpu && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/cpu)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/cuda
	(cd ${WRKSRC}/src/kernel/device/cuda && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/cuda)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/gpu
	(cd ${WRKSRC}/src/kernel/device/gpu && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/gpu)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/hip
	(cd ${WRKSRC}/src/kernel/device/hip && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/hip)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/hiprt
	(cd ${WRKSRC}/src/kernel/device/hiprt && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/hiprt)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/metal
	(cd ${WRKSRC}/src/kernel/device/metal && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/metal)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/oneapi
	(cd ${WRKSRC}/src/kernel/device/oneapi && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/oneapi)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/device/optix
	(cd ${WRKSRC}/src/kernel/device/optix && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/device/optix)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/film
	(cd ${WRKSRC}/src/kernel/film && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/film)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/geom
	(cd ${WRKSRC}/src/kernel/geom && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/geom)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/integrator
	(cd ${WRKSRC}/src/kernel/integrator && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/integrator)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/light
	(cd ${WRKSRC}/src/kernel/light && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/light)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/osl
	(cd ${WRKSRC}/src/kernel/osl && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/osl)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/sample
	(cd ${WRKSRC}/src/kernel/sample && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/sample)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/svm
	(cd ${WRKSRC}/src/kernel/svm && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/svm)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/kernel/util
	(cd ${WRKSRC}/src/kernel/util && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/kernel/util)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/scene
	(cd ${WRKSRC}/src/scene && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/scene)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/session
	(cd ${WRKSRC}/src/session && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/session)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/subd
	(cd ${WRKSRC}/src/subd && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/subd)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/util
	(cd ${WRKSRC}/src/util && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/util)

.include <bsd.port.mk>


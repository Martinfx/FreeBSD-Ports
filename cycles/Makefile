PORTNAME=	cycles
DISTVERSIONPREFIX=	v
DISTVERSION=	5.1.0
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Cycles is a physically based production renderer developed by Blender
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
		libtbb.so:devel/onetbb \
		libyaml-cpp.so:devel/yaml-cpp \
		libzstd.so:archivers/zstd

USES=		cmake:testing jpeg
USE_GITHUB=	yes
GH_ACCOUNT=	blender
GH_PROJECT=	cycles

CMAKE_ARGS=	-DOSL_SHADER_DIR:STRING="${LOCALBASE}/share/openshadinglanguage/shaders"

CMAKE_ON=	CMAKE_POSITION_INDEPENDENT_CODE WITH_CYCLES_ALEMBIC \
		WITH_CYCLES_DEVICE_ONEAPI WITH_CYCLES_OPENCOLORIO WITH_CYCLES_OPENIMAGEDENOISE \
		WITH_CYCLES_OPENSUBDIV WITH_CYCLES_OPENVDB WITH_CYCLES_OSL
CMAKE_OFF=	WITH_CYCLES_DEVICE_OPTIX WITH_CYCLES_NANOVDB WITH_LIBS_PRECOMPILED

OPTIONS_DEFINE=		EMBREE USD
EMBREE_DESC=		Collection of high-performance ray tracing kernels.
USD_DESC=		Hydra render delegate for USD, rendering of USD files
EMBREE_LIB_DEPENDS=	libembree4.so:graphics/embree
EMBREE_CMAKE_BOOL=	WITH_CYCLES_EMBREE
OPTIONS_EXCLUDE_aarch64=	EMBREE # graphics/embree is amd64/i386 only
OPTIONS_DEFAULT=	EMBREE USD
OPTIONS_SUB=		yes

USD_LIB_DEPENDS=	libusd_ms.so:graphics/openusd
USD_USES=		gl python xorg
USD_USE=		GL=gl XORG=ice,sm,x11,xext,xt
USD_CMAKE_BOOL=		WITH_CYCLES_HYDRA_RENDER_DELEGATE WITH_CYCLES_USD
USD_CMAKE_ON=		-DPXR_ROOT:PATH=${LOCALBASE} \
			-DPYTHON_VERSION:STRING=${PYTHON_VER}

.include <bsd.port.options.mk>

# On aarch64, the SIMD code of Cycles, also in its headers, is its SSE code
# translated by sse2neon.
.if ${ARCH} == aarch64
BUILD_DEPENDS+=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
RUN_DEPENDS+=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BUILD_WRKSRC%%|${BUILD_WRKSRC}|g' \
		${WRKSRC}/src/app/CMakeLists.txt

# hdCycles is installed into the USD plugin directory, and its resources
# (the Cycles resource path) are those in ${DATADIR}.
post-patch-USD-on:
	@${REINPLACE_CMD} -e 's|@PLUG_INFO_RESOURCE_PATH@|../../../share/cycles|' \
		${WRKSRC}/src/hydra/resources/plugInfo.json

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/cycles ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/*.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/app/opengl
	(cd ${WRKSRC}/src/app/opengl && ${COPYTREE_SHARE} "*.h" ${STAGEDIR}${PREFIX}/include/app/opengl)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/device
	(cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} device ${STAGEDIR}${PREFIX}/include/ "-name *.h")
	${MKDIR} ${STAGEDIR}${PREFIX}/include/
	(cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/ "-name *.h" )
# util/atomic.h includes atomic_ops.h of third_party/atomic by its name only,
# which is also that of a header of devel/libatomic_ops.
	${SED} -e 's|"atomic_ops.h"|"../third_party/atomic/atomic_ops.h"|' \
		${WRKSRC}/src/util/atomic.h > ${WRKDIR}/atomic.h
	${INSTALL_DATA} ${WRKDIR}/atomic.h ${STAGEDIR}${PREFIX}/include/util
	${MKDIR} ${STAGEDIR}${PREFIX}/include/third_party/atomic
	(cd ${WRKSRC}/third_party/atomic/ && ${COPYTREE_SHARE} *.h ${STAGEDIR}${PREFIX}/include/third_party/atomic/)
	${MKDIR} ${STAGEDIR}${PREFIX}/include/third_party/atomic/intern
	(cd ${WRKSRC}/third_party/atomic/intern && ${COPYTREE_SHARE} "*.h" ${STAGEDIR}${PREFIX}/include/third_party/atomic/intern)
# The Cycles resource path, which also holds the definitions this build used,
# for applications that link the libraries (graphics/gaffer).  The kernel
# sources that applications look for are the installed headers.
	@${MKDIR} ${STAGEDIR}${DATADIR}/shader
	${INSTALL_DATA} ${BUILD_WRKSRC}/cycles_definitions.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/kernel/osl/shaders/*.oso \
		${WRKSRC}/src/kernel/osl/shaders/*.h ${STAGEDIR}${DATADIR}/shader
	${RLN} ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${DATADIR}/source

do-install-USD-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/plugin/usd/hdCycles/resources
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/hydra/hdCycles.so \
		${STAGEDIR}${PREFIX}/plugin/usd
	${INSTALL_DATA} ${BUILD_WRKSRC}/src/hydra/resources/plugInfo.json \
		${STAGEDIR}${PREFIX}/plugin/usd/hdCycles/resources

.include <bsd.port.mk>
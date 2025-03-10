PORTNAME=	luxcorerender
DISTVERSIONPREFIX=	luxcorerender-
DISTVERSION=	2.9alpha4
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/lastrodamo/LuxCoreRender/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	LuxCoreRender is a physically based and unbiased rendering engine
WWW=		https://luxcorerender.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		boost-libs>=1.87.0:devel/boost-libs \
		c-blosc>0:archivers/c-blosc \
		doxygen>0:devel/doxygen \
		eigen>0:math/eigen3 \
		embree>0:graphics/embree \
		gtk3>0:x11-toolkits/gtk30 \
		harfbuzz>0:print/harfbuzz \
		nlohmann-json>0:devel/nlohmann-json \
		onetbb>0:devel/onetbb \
		opencl>0:devel/opencl \
		opencolorio>0:graphics/opencolorio \
		openexr>0:graphics/openexr \
		openimageio>0:graphics/openimageio \
		opensubdiv>0:graphics/opensubdiv \
		openvdb>0:misc/openvdb \
		pocl>0:lang/pocl \
		stb>0:devel/stb

LIB_DEPENDS=	libatk-1.0.so:accessibility/at-spi2-core \
		libblosc.so:archivers/c-blosc \
		libboost_atomic.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libembree3.so:graphics/embree \
		libfmt.so:devel/libfmt \
		libglfw.so:graphics/glfw \
		libharfbuzz.so:print/harfbuzz \
		libIex-3_3.so:graphics/openexr \
		libIlmThread-3_3.so:graphics/openexr \
		libImath-3_1.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR-3_3.so:graphics/openexr \
		libOpenEXRCore-3_3.so:graphics/openexr \
		libOpenEXRUtil-3_3.so:graphics/openexr \
		libOpenImageDenoise.so:graphics/oidn \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libopenvdb.so:misc/openvdb \
		libosdCPU.so:graphics/opensubdiv \
		libosdGPU.so:graphics/opensubdiv \
		libpng16.so:graphics/png \
		libspdlog.so:devel/spdlog \
		libtbb.so:devel/onetbb \
		libtiff.so:graphics/tiff

RUN_DEPENDES=	boost-libs>=1.87.0:devel/boost-libs libfmt>0:devel/libfmt \
		Imath>0:math/Imath oidn>0:graphics/oidn \
		openimageio>0:graphics/openimageio \
		opensubdiv>0:graphics/opensubdiv \
		opencolorio>0:graphics/opencolorio openvdb>0:misc/openvdb \
		openexr>0:graphics/openexr embree>0:graphics/embree \
		spdlog>0:devel/spdlog

USES=		bison cmake gettext-runtime jpeg localbase pkgconfig \
		python:3.11+
CMAKE_ON=	LUXRAYS_DISABLE_CUDA WIN_BUILD_DEMOS
CMAKE_OFF=	ENABLE_CUDA LUXRAYS_DISABLE_OPENCL
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GL=		gl glu opengl
USE_GNOME=	gnome cairo gdkpixbuf2 glib20 gtk30 pango

OPTIONS_DEFINE= 	OIDN
OPTIONS_DEFAULT=	OIDN
OPTIONS_SUB=		no
OIDN_DESC= 		Enable Intel Open Image Denoise support
OIDN_BUILD_DEPENDS=	oidn>0:graphics/oidn
OIDN_LIB_DEPENDS=	libOpenImageDenoise.so:graphics/oidn
OIDN_CMAKE_BOOL_OFF=	LUXCORE_DISABLE_OIDN

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreconsole ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoredemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreimplserializationdemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcorescenedemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${BUILD_WRKSRC}/luxcorerender.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/icons/luxcorerender.png \
		${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>

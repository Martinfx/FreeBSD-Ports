PORTNAME=	luxcorerender
DISTVERSIONPREFIX=luxcorerender-
DISTVERSION=	2.9alpha3
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/lastrodamo/LuxCoreRender/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	LuxCore renderer
WWW=		https://luxcorerender.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BUILD_DEPENDS=	boost-libs>=1.86.0:devel/boost-libs \
		${PYTHON_PKGNAMEPREFIX}boost-libs>0:devel/boost-python-libs@${PY_FLAVOR} \
		c-blosc>0:archivers/c-blosc \
		doxygen>0:devel/doxygen \
		harfbuzz>0:print/harfbuzz \
		openimageio>0:graphics/openimageio \
		opensubdiv>0:graphics/opensubdiv \
		opencolorio>0:graphics/opencolorio \
		oidn>0:graphics/oidn \
		onetbb>0:devel/onetbb \
		openexr>0:graphics/openexr \
		openvdb>0:misc/openvdb \
		opencl>0:devel/opencl \
		pocl>0:lang/pocl \
		gtk3>0:x11-toolkits/gtk30 \
		embree>0:graphics/embree \
		eigen>0:math/eigen3 \
		nlohmann-json>0:devel/nlohmann-json \
		stb>0:devel/stb

LIB_DEPENDS=	libboost_python${PYTHON_SUFFIX}.so:devel/boost-python-libs \
		libOpenColorIO.so:graphics/opencolorio \
		libosdCPU.so:graphics/opensubdiv \
		libosdGPU.so:graphics/opensubdiv \
		libopenvdb.so:misc/openvdb \
		libspdlog.so:devel/spdlog \
		libfmt.so:devel/libfmt  \
		libblosc.so:archivers/c-blosc \
		libembree3.so:graphics/embree \
		libOpenImageDenoise.so:graphics/oidn \
		libtbb.so:devel/onetbb \
		libtiff.so:graphics/tiff \
		libIex-3_3.so:graphics/openexr \
		libImath-3_1.so:math/Imath \
		libIlmThread-3_3.so:graphics/openexr \
		libOpenEXR-3_3.so:graphics/openexr \
		libOpenEXRCore-3_3.so:graphics/openexr \
		libOpenEXRUtil-3_3.so:graphics/openexr \
		libpng16.so:graphics/png \
		libboost_thread.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_serialization.so:devel/boost-libs \
		libboost_iostreams.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs\
		libboost_atomic.so:devel/boost-libs \
		libOpenImageIO.so:graphics/openimageio \
		libOpenImageIO_Util.so:graphics/openimageio \
		libglfw.so:graphics/glfw

USES=		bison cmake python:3.11+ pkgconfig localbase jpeg gettext-runtime
USE_GNOME=	cairo pango glib20 gtk30 gdkpixbuf2
CMAKE_OFF=	LUXCORE_DISABLE_OIDN LUXRAYS_DISABLE_OPENCL ENABLE_CUDA
CMAKE_ON=	LUXRAYS_DISABLE_CUDA WIN_BUILD_DEMOS
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreconsole ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoredemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreimplserializationdemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcorescenedemo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/bin/luxcoreui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${BUILD_WRKSRC}/luxcoreui.desktop \
			${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/luxcorerender/icons/uxcorerender.png \
		${STAGEDIR}${PREFIX}/share/icons

.include <bsd.port.mk>

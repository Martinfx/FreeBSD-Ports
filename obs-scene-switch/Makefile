PORTNAME=	obs-scene-switch
DISTVERSION=	1.32.6
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Advanced Scene Switcher
WWW=		https://github.com/WarmUpTill/SceneSwitcher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>0:ftp/curl \
		nlohmann-json>0:devel/nlohmann-json \
		opencv>0:graphics/opencv

LIB_DEPENDS=	libceres.so:math/ceres-solver \
		libcurl.so:ftp/curl \
		libdc1394.so:multimedia/libdc1394 \
		libgdal.so:graphics/gdal \
		libgdcmDSED.so:devel/gdcm \
		libgdcmMSFF.so:devel/gdcm \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgphoto2.so:graphics/libgphoto2 \
		libgphoto2_port.so:graphics/libgphoto2 \
		libharfbuzz.so:print/harfbuzzb \
		libhdf5.so:science/hdf \
		libjack.so:audio/jack \
		libobs-frontend-api.so:multimedia/obs-studio \
		libobs.so:multimedia/obs-studio \
		libopenblas.so:math/openblas \
		libopencv_dnn.so:graphics/opencv \
		libopencv_imgcodecs.so:graphics/opencv \
		libopencv_ml.so:graphics/opencv \
		libopencv_photo.so:graphics/opencv \
		libopencv_xfeatures2d.so:graphics/opencv \
		libopencv_ximgproc.so:graphics/opencv \
		libOpenEXR-3_4.so:graphics/openexr \
		libopenjp2.so:graphics/openjpeg \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake gl gnome localbase pkgconfig qt:6 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	WarmUpTill
GH_PROJECT=	SceneSwitcher
GH_TUPLE=	chriskohlhoff:asio:c465349:asio/deps/asio \
		yhirose:cpp-httplib:c7ed179:httplib/deps/cpp-httplib \
		HowardHinnant:date:5bdb7e6:date/deps/date \
		danielaparker:jsoncons:64b9da1:jsoncons/deps/jsoncons \
		DanBloomberg:leptonica:b667978:leptonica/deps/leptonica \
		tesseract-ocr:tesseract:080da83:tesseract/deps/tesseract \
		celtera:libremidi:73e6ea4:libremidi/deps/libremidi \
		ValveSoftware:openvr:4c85abc:openvr/deps/openvr \
		zaphoyd:websocketpp:56123c8:websocket/deps/websocketpp

USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base
USE_XORG=	ice sm x11 xext
CMAKE_OFF=	CMAKE_COMPILE_WARNING_AS_ERROR
USE_GSTREAMER1=	yes

.include <bsd.port.mk>

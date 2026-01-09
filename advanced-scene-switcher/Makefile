PORTNAME=	advanced-scene-switcher
DISTVERSION=	1.32.6
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Advanced Scene Switcher
WWW=		https://github.com/WarmUpTill/SceneSwitcher

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	curl>0:ftp/curl \
		libXScrnSaver>0:x11/libXScrnSaver \
		nlohmann-json>0:devel/nlohmann-json \
		opencv>0:graphics/opencv \
		simde>0:devel/simde

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjack.so:audio/jack \
		libobs-frontend-api.so:multimedia/obs-studio \
		libobs.so:multimedia/obs-studio \
		libopencv_dnn.so:graphics/opencv \
		libopencv_imgcodecs.so:graphics/opencv \
		libopencv_ml.so:graphics/opencv \
		libopencv_photo.so:graphics/opencv \
		libopencv_xfeatures2d.so:graphics/opencv \
		libopencv_ximgproc.so:graphics/opencv

USES=		cmake gl gnome jpeg localbase pkgconfig qt:6 xorg
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
USE_LDCONFIG=	yes

do-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/locale \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/cascadeClassifiers \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/images \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/ocr

	${INSTALL_DATA} \
		${WRKSRC}/data/locale/*.ini \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/locale

	${INSTALL_DATA} \
		${WRKSRC}/data/res/cascadeClassifiers/*.xml \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/cascadeClassifiers

	${INSTALL_DATA} \
		${WRKSRC}/data/res/images/*.svg \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/images

	${INSTALL_DATA} \
		${WRKSRC}/data/res/ocr/*.traineddata \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/${PORTNAME}/res/ocr

	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}-lib.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/${PORTNAME}-lib.so.1 \
		${STAGEDIR}${PREFIX}/lib/obs-plugins
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/base/advanced-scene-switcher-base.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/http/advanced-scene-switcher-http.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/midi/advanced-scene-switcher-midi.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/scripting/advanced-scene-switcher-scripting.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/stream-deck/advanced-scene-switcher-stream-deck.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/twitch/advanced-scene-switcher-twitch.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/usb/advanced-scene-switcher-usb.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}
	${INSTALL_LIB} \
		${BUILD_WRKSRC}/plugins/video/advanced-scene-switcher-opencv.so \
		${STAGEDIR}${PREFIX}/lib/obs-plugins/${PORTNAME}

.include <bsd.port.mk>

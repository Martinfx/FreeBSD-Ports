PORTNAME=	obs-scene-switch
DISTVERSION=	1.32.6
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Advanced Scene Switcher
WWW=		https://github.com/WarmUpTill/SceneSwitcher

BUILD_DEPENDS=	curl>0:ftp/curl \
		opencv>0:graphics/opencv \
		nlohmann-json>0:devel/nlohmann-json \
		libpaho-mqtt3>0:net/libpaho-mqtt3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl pkgconfig qt:6
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
USE_QT=		base
LDFLAGS=	-I/usr/include -L/usr/lib -lusb


.include <bsd.port.mk>

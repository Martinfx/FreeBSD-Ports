PORTNAME=	amber
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.6
CATEGORIES=	multimedia

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Amber Video Editor
WWW=		https://github.com/baptisterajaut/amber

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libavfilter.so:multimedia/ffmpeg \
		libavformat.so:multimedia/ffmpeg \
		libavutil.so:multimedia/ffmpeg \
		libswresample.so:multimedia/ffmpeg \
		libswscale.so:multimedia/ffmpeg \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake desktop-file-utils gl qt:6 shared-mime-info

USE_GITHUB=	yes
GH_ACCOUNT=	baptisterajaut
GH_PROJECT=	amber

USE_GL=		gl opengl
USE_QT=		base multimedia tools shadertools svg

CMAKE_SOURCE_PATH= ${WRKSRC}/src

.include <bsd.port.mk>

PORTNAME=	megasync
DISTVERSIONPREFIX=v
DISTVERSION=	6.1.1.0
DISTVERSIONSUFFIX=_Linux
CATEGORIES=	sysutils

MAINTAINER=	maxfx@hades
COMMENT=	Megasync tool
WWW=		https://example.com

BUILD_DEPENDES=	freeimage>0:graphics/freeimage \
		ffmpeg>0:multimedia/ffmpeg

LICENSE=	unknown
LICENSE_NAME=	MEGA LIMITED CODE LICENCE
LICENSE_TEXT=	see: https://github.com/meganz/MEGAsync/blob/master/LICENCE.md
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	meganz
GH_TUPLE=	meganz:sdk:1c13b13cb90c77f61e38d228b73a4a6fa8df67ca:sdk/src/MEGASync/mega

CMAKE_ON=	ENABLE_DESKTOP_APP ENABLE_QT_BINDINGS USE_FREEIMAGE
CMAKE_OFF=	USE_PDFIUM USE_BREAKPAD ENABLE_DESKTOP_UPDATE_GEN ENABLE_DESKTOP_APP_TESTS
WRKSRC=		${WRKDIR}/MEGAsync-${DISTVERSION}${DISTVERSIONSUFFIX}
#ALL_TARGET=	MEGAsync

.include <bsd.port.mk>

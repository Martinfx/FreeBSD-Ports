# $FreeBSD$

PORTNAME=       vcmi
PORTVERSION=    0.99
CATEGORIES=     games

MAINTAINER=     maintainer@email,com
COMMENT=        Opensource crossplatform Might Magic Heroes 3.

LICENSE=        GPLv2
LICENSE_FILE=   ${WRKSRC}/license.txt

USES=           cmake gl sdl compiler:c++17-lang qt:5

BUILD_DEPENDS=	boost-libs>=1.70.0:devel/boost-libs \
		googletest>=1.7.0:devel/googletest \
		minizip>=1.2.8:archivers/minizip \
		ffmpeg:multimedia/ffmpeg


USE_GITHUB=     yes
GH_ACCOUNT=     vcmi
GH_PROJECT=	vcmi
#GH_TAGNAME=	cc75b85

GH_TUPLE +=	fuzzylite:fuzzylite:9751a75:AI/FuzzyLite
GH_TUPLE +=	google:googletest:4bab34d:test/googletest

USE_GL=         gl glew
USE_SDL=        sdl2 mixer2 ttf2

.include <bsd.port.mk>


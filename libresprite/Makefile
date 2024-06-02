PORTNAME=       libresprite
DISTVERSIONPREFIX=v
DISTVERSION=    1.1
DISTVERSIONSUFFIX=-dev
CATEGORIES=     editors

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        Animated sprite editor & pixel art tool.
WWW=            libresprite.github.io/

USES=           cmake
USE_SDL=	sdl2 image

LICENSE=        GPLv2
LICENSE_FILE=   ${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	sdl2_image>0:graphics/sdl2_image

USE_GITHUB=     yes
GH_ACCOUNT=     LibreSprite
GH_PROJECT=     LibreSprite
GH_TUPLE+=	aseprite:clip:94693e2414a2c69a8ca16f065240c80a94cc6221:src/clip \
		aseprite:flic:876ef60df5fec606f8eb0638ee893e4967db4673:src/flic

.include <bsd.port.mk>

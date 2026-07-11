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

BUILD_DEPENDS=	curl>0:ftp/curl \
		sdl2_image>0:graphics/sdl2_image \
		freetype2>0:print/freetype2 \
		pixman>0:x11/pixman \
		tinyxml2>0:textproc/tinyxml2

USE_GITHUB=     yes
GH_ACCOUNT=     LibreSprite
GH_PROJECT=     LibreSprite
GH_TUPLE+=	aseprite:clip:94693e2414a2c69a8ca16f065240c80a94cc6221:clip/src/clip \
		aseprite:flic:876ef60df5fec606f8eb0638ee893e4967db4673:flic/src/flic \
		dacap:observable:8e03c3cb060120b25517503e6c1d9072686d1cd3:observadle/src/observable \
		aseprite:undo:f39b188e29d0f9adaa49c8705c0f492939d967a9:undo/src/undo \
		LibreSprite:duktape:6f715553e706b61e611aa4ae8e6fe90626800dae:duktape/third_party/duktape \
		aseprite:simpleini:c94997d4d64394833e4b9d21f4573c66600c9a9a:simpleini/third_party/simpleini

.include <bsd.port.mk>

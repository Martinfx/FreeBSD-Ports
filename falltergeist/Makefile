# $FreeBSD$

PORTNAME=	falltergeist
PORTVERSION=	0.3.1
CATEGORIES=	games

MAINTAINER=	maintainer@email.com
COMMENT=	Opensource crossplatform Fallout 2 game engine.

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		cmake:insource gl sdl localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	falltergeist

USE_GL=		gl glew
USE_SDL=	sdl2 mixer2 image2

PLIST_FILES=	bin/falltergeist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

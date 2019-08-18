# $FreeBSD$

PORTNAME=	anese
PORTVERSION=	0.9.1
CATEGORIES=	emulators

MAINTAINER=	maintainer@email.com
COMMENT=	NES emulator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:insource
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	daniel5151
GH_PROJECT=	ANESE
USE_LDCONFIG=	yes

PLIST_FILES=	bin/anese

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

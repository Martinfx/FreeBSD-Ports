# $FreeBSD$

PORTNAME=	v
DISTVERSION=	0.1.15
CATEGORIES=	lang

MAINTAINER=	maintainer@email.com
COMMENT=	Simple, fast, safe, compiled language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	vlang

PLIST_FILES=	bin/v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

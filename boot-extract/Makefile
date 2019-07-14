# $FreeBSD$

PORTNAME=	boot-extract
PORTVERSION=	g20190614
CATEGORIES=	sysutils

MAINTAINER=	maintainer@email.com
COMMENT=	Android Boot image extraction tool

LICENSE=	GPLv2

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	csimmonds
GH_PROJECT=	boot-extract
GH_TAGNAME=	486995f

PLIST_FILES=	bin/boot-extract

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
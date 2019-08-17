# $FreeBSD$

PORTNAME=	darling-dmg
PORTVERSION=	g20190817
CATEGORIES=	sysutils

MAINTAINER=	maintainer@email.cz
COMMENT=	FUSE module for .dmg files (containing an HFS+ filesystem

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ssl fuse
USE_GNOME=	libxml2
LIB_DEPENDS=	libicuuc.so:devel/icu

USE_GITHUB=	yes
GH_ACCOUNT=	darlinghq
GH_PROJECT=	darling-dmg
GH_TAGNAME=	9d19eb

.include <bsd.port.mk>

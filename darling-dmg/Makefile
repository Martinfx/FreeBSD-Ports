# $FreeBSD$

PORTNAME=	darling-dmg
PORTVERSION=	g20221019
CATEGORIES=	sysutils

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	FUSE module for .dmg files (containing an HFS+ filesystem
WWW= 		https://github.com/darlinghq/darling-dmg

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxml2>0:textproc/libxml2

USES=		cmake fuse
USE_GNOME=	libxml2
LIB_DEPENDS=	libicuuc.so:devel/icu

USE_GITHUB=	yes
GH_ACCOUNT=	darlinghq
GH_PROJECT=	darling-dmg
GH_TAGNAME=	8a2831

.include <bsd.port.mk>

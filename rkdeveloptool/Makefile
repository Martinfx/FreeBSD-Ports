# $FreeBSD$

PORTNAME=	rkdeveloptool
DISTVERSION=	g20200921
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Rkdeveloptool is a tool from Rockchip to communicate with Rockusb devices.

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libiconv.so:converters/libiconv

USES=		autoreconf:build iconv gmake

GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rockchip-linux
GH_PROJECT=	rkdeveloptool
GH_TAGNAME=	1e890c4

PLIST_FILES=	bin/rkdeveloptool

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -ivf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rkdeveloptool ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

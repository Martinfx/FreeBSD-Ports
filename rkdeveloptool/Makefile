# $FreeBSD$

PORTNAME=	rkdeveloptool
DISTVERSIONPREFIX=	v
DISTVERSION=	1.32
CATEGORIES=	sysutils

MAINTAINER=	maintainer@email.com
COMMENT=	Rkdeveloptool is a tool from Rockchip to communicate with Rockusb devices.

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		autoreconf pkgconfig

GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rockchip-linux
GH_PROJECT=	rkdeveloptool
GH_TAGNAME=	46bb4c0

PLIST_FILES=	bin/rkdeveloptool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rkdeveloptool ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

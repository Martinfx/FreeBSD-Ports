PORTNAME=	datovka
DISTVERSION=	4.21.0
CATEGORIES=	devel
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/${DISTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt re-implementation of Datovka.
WWW=		https://gitlab.nic.cz/datovka/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	graphics/libglvnd \
		libdatovka.so:devel/libdatovka

USES=		gl qmake qt:5 ssl tar:xz
USE_QT+=	core gui network printsupport sql svg websockets widgets

.include <bsd.port.mk>

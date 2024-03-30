PORTNAME=	datovka
DISTVERSION=	4.21.0
CATEGORIES=	mail
MASTER_SITES=	https://secure.nic.cz/files/datove_schranky/${DISTVERSION}/

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Qt re-implementation of Datovka.
WWW=		https://gitlab.nic.cz/datovka/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPEND+=	libdatovka>=0.2.1:devel/libdatovka \
		pkgconf:devel/pkgconf \
		graphics/libglvnd

LIB_DEPENDS+=	libdatovka.so:devel/libdatovka

USES=		desktop-file-utils pkgconfig qmake qt:5 tar:xz
USE_GL+=	gl
USE_QT+=	printsupport svg widgets gui websockets network sql core buildtools

.include <bsd.port.mk>

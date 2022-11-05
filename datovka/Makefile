PORTNAME=       datovka
DISTVERSION=    4.21.0
CATEGORIES=     devel
MASTER_SITES=   https://secure.nic.cz/files/datove_schranky/${DISTVERSION}/

MAINTAINER=     freebsd@sysctl.cz
COMMENT=        Qt re-implementation of Datovka.
WWW=            https://gitlab.nic.cz/datovka/

LICENSE=        LGPL3
LICENSE_FILE=   ${WRKSRC}/COPYING

LIB_DEPENDS+=   libdatovka.so:devel/libdatovka

USES=		qmake qt:5 tar:xz
QT+=		printsupport svg widgets gui websockets network sql core

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	reaver
PORTVERSION=	1.6.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/t6x/reaver-wps-fork-t6x/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	email@email
COMMENT=	Reaver brute force attack against Wifi Protected Setup WPS

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		autoreconf gmake

WRKSRC=		${WRKDIR}/reaver-wps-fork-t6x-${PORTVERSION}/src

PLIST_FILES=	bin/reaver \
		bin/wash \
		man/man1/reaver.1.gz

post-install:
		@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/reaver bin/wash
		@${RM} -r ${STAGEDIR}/var/lib
		${INSTALL_MAN} ${WRKSRC}/../docs/reaver.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

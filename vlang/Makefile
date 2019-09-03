# $FreeBSD$

PORTNAME=	v
DISTVERSION=	0.1.23.1
CATEGORIES=	lang

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Simple, fast, safe, compiled language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake

LDFLAGS+=	-lm
GH_PROJECT=     v
GH_ACCOUNT=	vlang
GH_TUPLE=       vlang:vc:0.1.20:vc/vc
USE_GITHUB=     yes

PLIST_FILES=	bin/v

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/vc/v.c -o ${WRKSRC}/v

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ./v -g test v)

.include <bsd.port.mk>

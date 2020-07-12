# $FreeBSD$

PORTNAME=	intel-qat
PORTVERSION=	1.7.b.3.7.0
CATEGORIES=	devel
MASTER_SITES=	https://01.org/sites/default/files/downloads/
DISTNAME=	qat${PORTVERSION}-00008

MAINTAINER=	maintainer@email.com
COMMENT=	Intel® QuickAssist Technology (QAT) QATzip Library

LICENSE_NAME=	BSD LICENSE
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	auto-accept

NO_WRKSUBDIR=	yes

USES=		compiler:c11 gmake

HAS_CONFIGURE=  yes
MAKE_ENV+=      BSD_MAKE="${MAKE}" V=1

CONFIGURE_ARGS=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		PREFIX="${PREFIX}"

.include <bsd.port.mk>


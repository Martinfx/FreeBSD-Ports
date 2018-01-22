# $FreeBSD$

PORTNAME=	anydesk
PORTVERSION=	2.9.1
CATEGORIES=	devel
MASTER_SITES=	https://download.anydesk.com/freebsd/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}-${ARCH_SUFFIX}

MAINTAINER=	email
COMMENT=	Fast remote desktop

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64	i386
ARCH_SUFFIX=	${ARCH:S/amd64/x86_64/:S/i386/i386/}

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

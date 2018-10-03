# $FreeBSD$

PORTNAME=	SASM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.10.0
CATEGORIES=	devel

MAINTAINER=	maintainer@email.com
COMMENT=	Simple IDE for NASM, MASM, GAS and FASM assembly languages

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	Dman95
USE_QT=		core gui network widgets buildtools_build
USE_GL=		gl

DATADIR=	${PREFIX}/share/sasm

.include <bsd.port.mk>

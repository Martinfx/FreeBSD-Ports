# $FreeBSD$

PORTNAME=	anydesk
PORTVERSION=	2.9.1
CATEGORIES=	devel
MASTER_SITES=	https://download.anydesk.com/freebsd/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}-${ARCH_SUFFIX}

MAINTAINER=	email@email.com
COMMENT=	Fast remote desktop

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64	i386
ARCH_SUFFIX=	${ARCH:S/amd64/x86_64/:S/i386/i386/}

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#ANYDESKDIR=	/share/anydesk
USE_GL=		gl
USE_GNOME=	gtk20 glib20 gdkpixbuf2 cairo
USE_XORG=	x11 xi xcb xrandr xtst xext xfixes xdamage
PLIST_FILES=	anydesk

do-install:
	@${INSTALL} -d ${STAGEDIR}${PREFIX}/share/applications
	@cd ${WRKSRC} && ${MKDIR} ${STAGEDIR}${PREFIX}

# The binary main program
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}

.include <bsd.port.mk>

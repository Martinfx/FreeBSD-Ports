# $FreeBSD: head/deskutils/anydesk/Makefile 484672 2018-11-11 09:32:19Z sunpoet $

PORTNAME=	anydesk
DISTVERSION=	5.1.0
CATEGORIES=	deskutils
MASTER_SITES=	https://download.anydesk.com/freebsd/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}-${ARCH:S/amd64/x86_64/:S/i386/i386/}

MAINTAINER=	maintainer@email.cz
COMMENT=	Fast remote desktop

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software
LICENSE_PERMS=	auto-accept

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpolkit-gobject-1.so:sysutils/polkit \
		libinotify.so:devel/libinotify

USE_GL=		gl glu
USE_GNOME=	gtk20 glib20 gdkpixbuf2 cairo pangox-compat
USE_XORG=	x11 xi xcb xrandr xtst xext xfixes xdamage xrender
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/anydesk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

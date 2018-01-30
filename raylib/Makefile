# $FreeBSD$

PORTNAME=	raylib
PORTVERSION=	1.9.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Martinfx/raylib/archive/
DISTNAME=	${PORTVERSION}-dev

MAINTAINER=	email
COMMENT=	Simple and easy-to-use library to learn videogames programming

LICENSE=	ZLIB

LIB_DEPENDS=	libopenal.so:audio/openal-soft

USES=		cmake openal:al
USE_LDCONFIG=	yes
USE_XORG=	x11 sm ice xext xrandr xi xinerama xxf86vm xcursor

LDFLAGS+=	-L${LOCALBASE}/lib

CMAKE_ARGS=	-DSTATIC_RAYLIB:BOOL=ON \
		-DSHARED_RAYLIB:BOOL=ON \
		-DBUILD_EXAMPLES:BOOL=OFF \
		-DBUILD_GAMES:BOOL=OFF

PORTDOCS=	*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}

PLIST_FILE=	include/raylib.h \
		lib/libraylib.a \
		lib/libraylib.so \
		libdata/pkgconfig/raylib.pc

.include <bsd.port.mk>

PORTNAME=	mysql-workbench
DISTVERSION=	8.0.36
CATEGORIES=	editors
MASTER_SITES=	https://dev.mysql.com/get/Downloads/MySQLGUITools/:sql \
		https://www.antlr.org/download/:jar
DISTFILES=	${PORTNAME}-community-${DISTVERSION}-src.tar.gz:sql \
		antlr-4.11.1-complete.jar:jar
EXTRACT_ONLY=	${PORTNAME}-community-${DISTVERSION}-src.tar.gz

MAINTAINER=	maxfx@hades
COMMENT=	mysql editor

LICENSE=	GPLv2

USES=		cmake gnome
USES_GNOME=	gtk30 cairo

CPPFLAGS+=	 -I${LOCALBASE}/include \
		 -I${WRKSRC}/library/forms/gtk/src/
LDFLAGS+=	 -L${LOCALBASE}/lib

CMAKE_ARGS+=	-DODBC_INCLUDE_DIRS="/usr/local/include/" \
		-DODBC_LIBRARIES="/usr/local/lib" \
		-DANTLR_JAR_PATH=${WRKDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-community-${DISTVERSION}-src

.include <bsd.port.mk>

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

USES=		cmake gnome perl5 pkgconfig mysql:80 localbase:ldflags
USES_GNOME=	gtk30 cairo
USE_XORG=	x11
USE_PERL5=	configure

BUILD_DEPENDS+=	antlr4>0:devel/antlr4 \
		libssh>0:security/libssh \
		gtk3>0:x11-toolkits/gtk30 \
		gtkmm30>0:x11-toolkits/gtkmm30 \
		pcre>0:devel/pcre \
		p5-Data-UUID>0:devel/p5-Data-UUID \
		mysql-connector-c++>0:databases/mysql-connector-c++ \
		rapidjson>0:devel/rapidjson \
		gdal>0:graphics/gdal \
		vsqlite>0:databases/vsqlite \
		swig:devel/swig

CPPFLAGS+=	 -I${LOCALBASE}/include \
		 -I${WRKSRC}/library/forms/gtk/src \
		 -I${LOCALBASE}/include/cairo/ \
		 -I${LOCALBASE}/include `pkg-config --cflags gtk+-3.0`
LDFLAGS+=	 -L${LOCALBASE}/lib

CMAKE_ARGS+=	-DODBC_INCLUDE_DIRS="/usr/local/include/" \
		-DODBC_LIBRARIES="/usr/local/lib" \
		-DANTLR_JAR_PATH=${WRKDIR} \
		-DX11_X11_INCLUDE_PATH="/usr/local/include" \
		-DX11_X11_LIB="/usr/local/lib" \
		-DSWIG_EXECUTABLE="${LOCALBASE}/bin/swig" \
		-DSWIG_DIR="${LOCALBASE}/share/swig/4.1.1" \
		-DANTLR4_LIBRARY="${LOCALBASE}/lib" \
		-DANTLR4_INCLUDE_DIR="${LOCALBASE}/include" \
		-DMySQLCppConn_INCLUDE_DIR="${LOCALBASE}/include/jdbc/"

WRKSRC=		${WRKDIR}/${PORTNAME}-community-${DISTVERSION}-src

.include <bsd.port.mk>

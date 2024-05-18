PORTNAME=	mysql-workbench
DISTVERSION=	8.0.36
CATEGORIES=	editors
MASTER_SITES=	https://dev.mysql.com/get/Downloads/MySQLGUITools/
DISTNAME=	${PORTNAME}-community-${DISTVERSION}-src

MAINTAINER=	maxfx@hades
COMMENT=	mysql editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake

CMAKE_ARGS+=	-DODBC_INCLUDE_DIRS="/usr/local/include/" \
		-DODBC_LIBRARIES="/usr/local/lib" \
		-DANTLR_JAR_PATH=${WRKDIR}
		#-D
		#
		#"/usr/local/bin/odbc_config
pre-patch:
	fetch https://www.antlr.org/download/antlr-4.11.1-complete.jar
	mv antlr-4.11.1-complete.jar ${WRKDIR}

.include <bsd.port.mk>

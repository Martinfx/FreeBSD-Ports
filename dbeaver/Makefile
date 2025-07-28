PORTNAME=	dbeaver
DISTVERSION=	25.1.3
CATEGORIES=	editors

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Free universal database tool and SQL client.
WWW=		https://dbeaver.io

USES=		pkgconfig

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	maven39>0:devel/maven39

USES=		java:build
USE_GITHUB=	yes
GH_ACCOUNT=	dbeaver
GH_PROJECT=	dbeaver
GH_TUPLE=	dbeaver:dbeaver-common:8be2658:dbeavercommon \
		dbeaver:dbeaver-jdbc-libsql:221cc34:jdbc

#USE_JAVA=	17+
JAVA_VERSION=	21+
JAVA_VENDOR=	openjdk
#JAVA_RUN=	yes

#NO_BUILD=	yes

MAVEN_ENV=	MAVEN_OPTS=-Xmx1024m CC=${CC} CFLAGS="${CFLAGS}" JAVA_HOME=${JAVA_HOME}

pre-configure:
	@mv ${WRKDIR}/dbeaver-common-8be2658 ${WRKDIR}/dbeaver-common
	@mv ${WRKDIR}/dbeaver-jdbc-libsql-221cc34 ${WRKDIR}/dbeaver-jdbc-libsql

do-configure:
	@cd ${WRKSRC}/product/aggregate && ${SETENV} ${MAVEN_ENV} mvn clean install \
					    -Pall-platforms -T 1C -DskipTests verify \
					    -Duser.home=${WRKDIR} \
				            -Dmaven.repo.local=${WRKDIR}/m2

#do-install:

.include <bsd.port.mk>

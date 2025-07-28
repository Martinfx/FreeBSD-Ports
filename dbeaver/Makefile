PORTNAME=	dbeaver
DISTVERSION=	25.1.3
CATEGORIES=	editors

MAINTAINER=		freebsd@sysctl.cz
COMMENT=		Free universal database tool and SQL client.
WWW=			https://dbeaver.io

LICENSE=        APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE.md

BUILD_DEPENDS=  maven>0:devel/maven

USES=           java:build
USE_GITHUB=     yes
GH_ACCOUNT=     dbeaver
GH_PROJECT=     dbeaver
GH_TUPLE=       dbeaver:dbeaver-common:8be2658:dbeavercommon \
                dbeaver:dbeaver-jdbc-libsql:221cc34:jdbc

JAVA_VERSION=   21+
JAVA_VENDOR=	openjdk

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAVEN_ARCH=     x86_64
.elif ${ARCH} == "i386"
MAVEN_ARCH=     x86
.else
MAVEN_ARCH=     ${ARCH}
.endif

.include <bsd.port.pre.mk>

MAVEN_ENV=      MAVEN_OPTS=-Xmx1024m  JAVA_HOME=${JAVA_HOME}

pre-configure:
        @mv ${WRKDIR}/dbeaver-common-8be2658 ${WRKDIR}/dbeaver-common
        @mv ${WRKDIR}/dbeaver-jdbc-libsql-221cc34 ${WRKDIR}/dbeaver-jdbc-libsql

do-build:
        @cd ${WRKSRC}/product/aggregate && ${SETENV} ${MAVEN_ENV} ${LOCALBASE}/bin/mvn  \
                                            -Dnative=gtk.freebsd.${MAVEN_ARCH} -T 1C -DskipTests verify \
                                            -Duser.home=${WRKDIR} \
                                            -Dmaven.repo.local=${WRKDIR}/m2

do-install:

.include <bsd.port.post.mk>



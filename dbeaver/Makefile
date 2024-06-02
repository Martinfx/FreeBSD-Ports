PORTNAME=	dbeaver
DISTVERSION=	24.0.5
CATEGORIES=	editors
MASTER_SITES=	https://github.com/dbeaver/dbeaver-common/archive/refs/tags/:source1
DISTFILES=      23.2.5${EXTRACT_SUFX}:source1
DIST_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Free universal database tool and SQL client.
WWW=		dbeaver.io

USES=		pkgconfig

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	maven39>0:devel/maven39 \
		openjdk17>0:java/openjdk17

USE_GITHUB=	yes
GH_ACCOUNT=	dbeaver
GH_PROJECT=	dbeaver

USE_JAVA=	17+
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

NO_BUILD=	yes

MAVEN_ENV=	MAVEN_OPTS=-Xmx1024m CC=${CC} CFLAGS="${CFLAGS}" JAVA_HOME=${JAVA_HOME}

pre-configure:
	@mv ${WRKDIR}/dbeaver-common-23.2.5 ${WRKDIR}/dbeaver-common
do-configure:
	@cd ${WRKSRC}/product/aggregate && ${SETENV} ${MAVEN_ENV} mvn clean install \
					    -Pall-platforms -T 1C -DskipTests verify \
					    -Duser.home=${WRKDIR} \
				            -Dmaven.repo.local=${WRKDIR}/m2

#do-install:

.include <bsd.port.mk>

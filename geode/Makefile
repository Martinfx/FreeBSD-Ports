PORTNAME=	geode
PORTVERSION=	1.15.1
MASTER_SITES=	https://archive.apache.org/dist/geode/${PORTVERSION}/
DISTFILES= 	apache-geode-${PORTVERSION}-src.tgz
CATEGORIES=	databases java

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Providing low latency, high concurrency data management solutions
WWW=		https://geode.incubator.apache.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	gradle>0:devel/gradle
RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix
CPE_VENDOR=	apache
#USE_JAVA=	yes
#SHEBANG_FILES=	bin/flume-ng
WRKSRC=		${WRKDIR}/apache-geode-${PORTVERSION}-src

USE_JAVA=	yes
JAVA_VERSION=	8+
##JAVA_BUILD=	yes
#JAVA_RUN=	yes

GRADLE_HOME_BASE=	/tmp
GRADLE_RUN=		${SETENV} ${MAKE_ENV} gradle --parallel generate --gradle-user-home \
			${GRADLE_HOME_BASE}/gradle-${PORTNAME}

#MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} \
#		MAVEN_OPTS="-Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m"

do-build:
	cd ${WRKSRC} && ${GRADLE_RUN}
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
#			${LOCALBASE}/bin/mvn ${OFFLINE} \
#		-Duser.home=${WRKDIR} \
#		-Dmaven.repo.local=${WRKDIR}/m2  \
#		 -DskipTests clean package

.include <bsd.port.mk>

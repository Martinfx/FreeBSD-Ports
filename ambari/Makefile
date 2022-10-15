PORTNAME=	ambari
PORTVERSION=	2.7.6
MASTER_SITES=	https://dlcdn.apache.org/ambari/${PORTNAME}-${PORTVERSION}/
DISTNAME= 	apache-ambari-${PORTVERSION}-src
CATEGORIES=	databases java

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	The Apache Ambari project is aimed at making Hadoop management simpler by developing \
		software for provisioning, managing, and monitoring Apache Hadoop clusters.
WWW=		https://ambari.apache.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	mvn:devel/maven \
		node:www/node \
		libinotify>0:devel/libinotify
RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
#SHEBANG_FILES=	bin/flume-ng

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		MAVEN_OPTS="-Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2 \
		versions:set -DnewVersion=2.7.6.0.0 \
		 -DskipTests clean package

.include <bsd.port.mk>

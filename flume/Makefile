PORTNAME=	flume
PORTVERSION=	1.10.1
CATEGORIES=	databases java
MASTER_SITES=	APACHE/flume
DISTNAME=	apache-flume-${PORTVERSION}-src

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Flume is a distributed, reliable, and available service for efficiently \
		collecting, aggregating, and moving large amounts of log data
WWW=		https://flume.apache.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	mvn:devel/maven
RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
SHEBANG_FILES=	bin/flume-ng

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		MAVEN_OPTS="-Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2  \
		 -DskipTests clean package
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/conf  ${STAGEDIR}${DATADIR}/tools
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-${PORTVERSION}-bin/apache-flume-${PORTVERSION}-bin/bin/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-${PORTVERSION}-bin/apache-flume-${PORTVERSION}-bin/lib/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-${PORTVERSION}-bin/apache-flume-${PORTVERSION}-bin/tools/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/

.include <bsd.port.mk>

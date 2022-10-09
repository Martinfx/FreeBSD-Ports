PORTNAME=	flume
PORTVERSION=	1.10.1
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTVERSION}/
DISTFILES=	apache-${PORTNAME}-${PORTVERSION}-src.tar.gz

CATEGORIES=	databases java

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Flume is a distributed, reliable, and available service for efficiently collecting, \
		aggregating, and moving large amounts of log data
WWW=		https://flume.apache.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	mvn:devel/maven
RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
SHEBANG_FILES=	bin/flume-ng

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}-src

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		MAVEN_OPTS="-Xms512m -Xmx1024m -XX:PermSize=256m -XX:MaxPermSize=512m"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
JAVA_ARCH=	x86_64
.elif ${ARCH} == "i386"
JAVA_ARCH=	x86
.else
JAVA_ARCH=	${ARCH}
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2  \
		 -DskipTests clean package
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/conf  ${STAGEDIR}${DATADIR}/tools
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-1.10.1-bin/apache-flume-1.10.1-bin/bin/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-1.10.1-bin/apache-flume-1.10.1-bin/lib/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC}/flume-ng-dist/target/apache-flume-1.10.1-bin/apache-flume-1.10.1-bin/tools/ && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/tools
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/

.include <bsd.port.post.mk>

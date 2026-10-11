PORTNAME=	mahout
DISTVERSION=	14.1
CATEGORIES=	math java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${DISTVERSION}/ \
		APACHE/${PORTNAME}/${DISTVERSION}
DISTNAME=	apache-${PORTNAME}-distribution-${DISTVERSION}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Distributed linear algebra framework with an R-like Scala DSL
WWW=		https://mahout.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# The binary distribution bundles no logging implementation at all; under
# Spark one comes from Spark itself, but the jars are unusable standalone
# without at least slf4j-api on the classpath.
RUN_DEPENDS=	${JAVALIBDIR}/slf4j-api.jar:devel/slf4j

USES=		cpe java
CPE_VENDOR=	apache

# Mahout ${DISTVERSION} is published for Scala 2.11 only, and Scala 2.11 does
# not support JDK 9 or newer.
JAVA_VERSION=	8
JAVA_RUN=	yes

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

SCALA_VER=	2.11
SLF4J_DIR=	${JAVASHAREDIR}/slf4j

SUB_FILES=	mahout pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		SCALA_VER=${SCALA_VER} \
		SLF4J_DIR=${SLF4J_DIR} \
		VERSION=${DISTVERSION}
PLIST_SUB=	SCALA_VER=${SCALA_VER} \
		VERSION=${DISTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${DATADIR}/bin \
		${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mahout ${STAGEDIR}${PREFIX}/bin/mahout
	${INSTALL_DATA} ${WRKSRC}/bin/load-shell.scala ${STAGEDIR}${DATADIR}/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${DATADIR}/lib/
	${INSTALL_DATA} ${WRKSRC}/conf/log4j.properties \
		${STAGEDIR}${ETCDIR}/log4j.properties.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${STAGEDIR}${DOCSDIR}

# examples/bin/run-item-sim.sh is deliberately left out: it drives
# spark-itemsimilarity, one of the command line drivers removed in 14.1.
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/resources
	${INSTALL_DATA} ${WRKSRC}/examples/bin/*.mscala \
		${WRKSRC}/examples/bin/*.scala ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/bin/resources/*.txt \
		${STAGEDIR}${EXAMPLESDIR}/resources

.include <bsd.port.mk>

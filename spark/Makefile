PORTNAME=	spark
PORTVERSION=	4.2.0
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast big data processing engine
WWW=		https://spark.apache.org/

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_i386=	not enough memory on this architecture to build the port
BROKEN_powerpc=	not enough memory on this architecture to build the port

BUILD_DEPENDS=	${LOCALBASE}/lib/libsnappyjava.so:archivers/snappy-java \
		bash:shells/bash \
		maven39>0:devel/maven39 \
		protoc:devel/protobuf
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++17-lang cpe java pkgconfig python shebangfix
CPE_VENDOR=	apache
JAVA_VERSION=	17 21

# Maven Central has no protoc and protoc-gen-grpc-java for FreeBSD, so the
# protobuf sources are compiled with protoc from devel/protobuf and the gRPC
# stubs of Spark Connect with a protoc-gen-grpc-java built from grpc-java.
USE_GITHUB=	nodefault
GH_TUPLE=	grpc:grpc-java:v1.76.0:grpcjava

USE_RC_SUBR=	spark_master spark_worker
SHEBANG_FILES=	bin/sparkR

NO_ARCH=	yes

SUB_LIST=	SPARK_GROUP=spark \
		SPARK_USER=spark

USERS=		spark
GROUPS=		spark

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?} || ${ARCH} == "i386"
MAKE_ENV+=	MAVEN_OPTS="-Xss64m -Xmx1g -XX:ReservedCodeCacheSize=1g" \
		JAVA_HOME=${JAVA_HOME}
.else
MAKE_ENV+=	MAVEN_OPTS="-Xss64m -Xmx4g -XX:ReservedCodeCacheSize=1g" \
		JAVA_HOME=${JAVA_HOME}
.endif

.if ${ARCH} == "amd64"
JAVA_ARCH=	x86_64
.elif ${ARCH} == "i386"
JAVA_ARCH=	x86
.else
JAVA_ARCH=	${ARCH}
.endif

# Update ${PORTNAME}-${PORTVERSION}-deps.tgz if the hadoop version is changed!
HADOOP_VERSION=	3.5.0

# To create the local maven repository (m2) run: make -DMAINTAINER_MODE build
# and then: make -DMAINTAINER_MODE make-deps
# The deps tarball is built by .github/workflows/spark-deps.yml and published
# in the spark-${PORTVERSION} release of github.com/Martinfx/FreeBSD-Ports.
.if !defined(MAINTAINER_MODE)
MASTER_SITES+=	https://github.com/Martinfx/FreeBSD-Ports/releases/download/spark-${PORTVERSION}/:deps
DISTFILES+=	${PORTNAME}-${PORTVERSION}-deps.tgz:deps
OFFLINE=	-o
.endif # !defined(MAINTAINER_MODE)

MAKE_ENV+=	SPARK_PROTOC_EXEC_PATH=${LOCALBASE}/bin/protoc \
		CONNECT_PLUGIN_EXEC_PATH=${WRKDIR}/protoc-gen-grpc-java

pre-build:
	${CXX} ${CXXFLAGS} -std=c++17 \
		$$(pkg-config --cflags protobuf) \
		-o ${WRKDIR}/protoc-gen-grpc-java \
		${WRKSRC_grpcjava}/compiler/src/java_plugin/cpp/java_generator.cpp \
		${WRKSRC_grpcjava}/compiler/src/java_plugin/cpp/java_plugin.cpp \
		${LDFLAGS} -lprotoc $$(pkg-config --libs protobuf)

do-build:
	${MKDIR} ${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	${CP} ${LOCALBASE}/lib/libsnappyjava.so \
		${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2 \
		-Dhadoop.version=${HADOOP_VERSION} \
		-Dmaven.version=3.9 \
		-Pyarn -Phive -Phive-thriftserver -Puser-defined-protoc \
		-DskipTests \
		clean package
	${JAR} uvf ${WRKSRC}/assembly/target/scala*/jars/snappy-java-*.jar \
		-C ${WRKDIR}/snappy org

post-build:
	${RM} ${WRKSRC}/bin/*.cmd ${WRKSRC}/sbin/spark-daemon.sh.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/examples/jars ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/sbin ${STAGEDIR}${DATADIR}/conf
	${ECHO_CMD} "Spark ${PORTVERSION} built for Hadoop ${HADOOP_VERSION}" > ${STAGEDIR}${DATADIR}/RELEASE
	(cd  ${WRKSRC}/assembly/target/scala* && ${COPYTREE_SHARE} jars  ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/examples/target/scala*/jars/spark-examples*.jar ${STAGEDIR}${DATADIR}/examples/jars
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}/examples
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/sbin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "python" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/
	${MKDIR} ${STAGEDIR}/var/run/spark
	${MKDIR} ${STAGEDIR}/var/log/spark

make-deps:
	cd ${WRKDIR} && ${TAR} -czf ${DISTDIR}/${PORTNAME}-${PORTVERSION}-deps.tgz m2

.include <bsd.port.post.mk>

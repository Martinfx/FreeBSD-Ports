PORTNAME=	hadoop
PORTVERSION=	3.5.0
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/common/${PORTNAME}-${PORTVERSION}/ \
		https://github.com/protocolbuffers/protobuf/releases/download/v${PROTOBUF_VERSION}/:protobuf
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		protobuf-${PROTOBUF_VERSION}${EXTRACT_SUFX}:protobuf
DIST_SUBDIR=	hadoop

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Apache Map/Reduce framework
WWW=		https://hadoop.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/cmake/absl/abslConfig.cmake:devel/abseil \
		bash:shells/bash \
		mvn:devel/maven
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash \
		setsid:sysutils/setsid

USES=		cmake:indirect compiler:c++17-lang cpe java pkgconfig \
		shebangfix ssl
CPE_VENDOR=	apache
JAVA_VERSION=	17
USE_LDCONFIG=	yes

SHEBANG_FILES=	hadoop-common-project/hadoop-kms/src/main/conf/kms-env.sh \
		hadoop-common-project/hadoop-kms/src/main/sbin/kms.sh \
		hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/conf/httpfs-env.sh \
		hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/sbin/httpfs.sh \
		hadoop-tools/hadoop-sls/src/main/bin/rumen2sls.sh \
		hadoop-tools/hadoop-sls/src/main/bin/slsrun.sh

CONFLICTS_INSTALL=	yarn

# Hadoop generates its Java protobuf code with protoc ${PROTOBUF_VERSION} and
# shades the matching protobuf-java runtime.  protoc is normally downloaded
# from Maven Central as a prebuilt binary, which does not exist for FreeBSD,
# and devel/protobuf is far too new to produce code that runtime accepts, so
# build exactly that protoc from source first.
PROTOBUF_VERSION=	25.5
PROTOBUF_WRKSRC=	${WRKDIR}/protobuf-${PROTOBUF_VERSION}
PROTOC_WRKDIR=		${WRKDIR}/protoc-build
PROTOC=			${PROTOC_WRKDIR}/protoc

MAKE_ENV+=	HADOOP_PROTOC_PATH=${PROTOC} \
		JAVA_HOME=${JAVA_HOME}

OPTIONS_DEFINE=	EXAMPLES

HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}

HADOOP_LOGDIR=	/var/log/hadoop
HADOOP_RUNDIR=	/var/run/hadoop

HDFS_USER=	hdfs
MAPRED_USER=	mapred
HADOOP_GROUP=	hadoop
USERS=		${HDFS_USER} ${MAPRED_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop-layout.sh httpfs-env.sh kms-env.sh pkg-message

USE_RC_SUBR=	historyserver nodemanager resourcemanager webappproxyserver \
		datanode namenode secondarynamenode journalnode zkfc

PLIST_SUB=	HADOOP_GROUP="${HADOOP_GROUP}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HDFS_USER="${HDFS_USER}" \
		MAPRED_USER="${MAPRED_USER}" \
		PORTVERSION="${PORTVERSION}"
SUB_LIST=	HADOOP_GROUP="${HADOOP_GROUP}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HDFS_USER="${HDFS_USER}" \
		JAVA_HOME="${JAVA_HOME}" \
		MAPRED_USER="${MAPRED_USER}"

post-patch:
# FreeBSD has no /bin/bash; the scripts Hadoop generates at runtime and the
# shell it runs tasks under have to point at ${LOCALBASE}/bin/bash.
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java \
		${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/containermanager/launcher/ContainerLaunch.java \
		${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/MRJobConfig.java \
		${WRKSRC}/hadoop-tools/hadoop-archive-logs/src/main/java/org/apache/hadoop/tools/HadoopArchiveLogs.java
# Replaced by the likely()/unlikely() definitions the commons.h patch adds.
	@${RM} ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/primitives.h

pre-build:
	${MKDIR} ${PROTOC_WRKDIR}
	cd ${PROTOC_WRKDIR} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="${CC}" -DCMAKE_CXX_COMPILER="${CXX}" \
		-DCMAKE_CXX_STANDARD=17 \
		-DCMAKE_PREFIX_PATH="${LOCALBASE}" \
		-Dprotobuf_ABSL_PROVIDER=package \
		-Dprotobuf_BUILD_LIBUPB=OFF \
		-Dprotobuf_BUILD_SHARED_LIBS=OFF \
		-Dprotobuf_BUILD_TESTS=OFF \
		-Dprotobuf_INSTALL=OFF \
		-Dprotobuf_WITH_ZLIB=OFF \
		${PROTOBUF_WRKSRC}
	${CMAKE_BIN} --build ${PROTOC_WRKDIR} --target protoc \
		--parallel ${MAKE_JOBS_NUMBER}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mvn \
		-Dmaven.javadoc.skip=true -Dmaven.clean.skip=true \
		-Dmaven.repo.local=${WRKDIR}/m2 package -Pdist,native -DskipTests \
		-DprotocExecutable=${PROTOC} \
		-Drequire.bzip2 \
		-Drequire.snappy -Dsnappy.prefix=${LOCALBASE} \
		-Drequire.zstd -Dzstd.prefix=${LOCALBASE} \
		-Drequire.openssl -Dopenssl.prefix=${OPENSSLBASE}

post-build:
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd

do-install:
	cd ${HADOOP_DIST}/bin && ${INSTALL_SCRIPT} hadoop hdfs mapred yarn ${STAGEDIR}${PREFIX}/bin/
	cd ${HADOOP_DIST} && ${COPYTREE_BIN} "libexec sbin" ${STAGEDIR}${PREFIX}/ "! -name *.cmd"
	cd ${HADOOP_DIST}/include && ${INSTALL_DATA} *h ${STAGEDIR}${PREFIX}/include/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib/
.for lib in libhadoop.so.1.0.0 libhdfs.so.0.0.0 libnativetask.so.1.0.0
	${INSTALL_LIB} ${HADOOP_DIST}/lib/native/${lib} ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf ${lib} ${STAGEDIR}${PREFIX}/lib/${lib:R:R:R}
.endfor
	cd ${HADOOP_DIST}/share/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DATADIR}/ "! -name *-sources.jar -and ! -name sources"
	${INSTALL_DATA} ${WRKDIR}/hadoop-layout.sh ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/httpfs-env.sh ${STAGEDIR}${ETCDIR}/httpfs-env.sh.sample
	${INSTALL_DATA} ${WRKDIR}/kms-env.sh ${STAGEDIR}${ETCDIR}/kms-env.sh.sample
	${INSTALL_DATA} ${HADOOP_DIST}/etc/hadoop/core-site.xml ${STAGEDIR}${ETCDIR}/core-site.xml.sample
	${INSTALL_DATA} ${HADOOP_DIST}/etc/hadoop/log4j.properties ${STAGEDIR}${ETCDIR}/log4j.properties.sample
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

# The sample configuration is listed in pkg-plist under %%PORTEXAMPLES%%, so it
# must only be staged when the option is on, or stage-qa trips over the orphans.
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/conf
	cd ${HADOOP_DIST}/etc/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${EXAMPLESDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs/target/classes/hdfs-default.xml ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/target/classes/httpfs-default.xml ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-common/target/classes/yarn-default.xml ${WRKSRC}/hadoop-common-project/hadoop-common/target/classes/core-default.xml ${WRKSRC}/hadoop-tools/hadoop-distcp/target/classes/distcp-default.xml ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/target/classes/mapred-default.xml ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>

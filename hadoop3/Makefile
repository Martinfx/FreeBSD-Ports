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

BUILD_DEPENDS=	bash:shells/bash \
		mvn:devel/maven
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libboost_date_time.so:devel/boost-libs \
		libprotobuf.so:devel/protobuf \
		libsasl2.so:security/cyrus-sasl2 \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash \
		setsid:sysutils/setsid

USES=		cmake:indirect compiler:c++17-lang cpe java pkgconfig \
		shebangfix ssl
USE_GITHUB=	nodefault
GH_TUPLE=	grpc:grpc-java:v${GRPC_JAVA_VERSION}:grpcjava
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

# The maven build normally downloads two code generators from Maven Central
# as prebuilt executables, and neither exists for FreeBSD:
#  - protoc ${PROTOBUF_VERSION}: Hadoop's Java protobuf code must come from
#    exactly this release to match the protobuf-java runtime it shades;
#    devel/protobuf is much newer and emits code that runtime rejects.
#  - protoc-gen-grpc-java, for the YARN CSI adaptor.
# Build both from source against devel/abseil (files/protoc-tools.cmake).
# The native libhdfs++ client, on the other hand, uses devel/protobuf.
PROTOBUF_VERSION=	25.5
GRPC_JAVA_VERSION=	1.69.0
PROTOC_TOOLS_SRC=	${WRKDIR}/protoc-tools
PROTOC_TOOLS_BUILD=	${WRKDIR}/protoc-tools-build
PROTOC=			${PROTOC_TOOLS_BUILD}/protobuf/protoc-${PROTOBUF_VERSION}.0
# Only the grpc plugin goes on PATH: a protoc there would shadow devel/protobuf's
# when CMake looks for one to build libhdfs++.
GRPC_PLUGIN_DIR=	${WRKDIR}/grpc-plugin-bin

MAKE_ENV+=	HADOOP_PROTOC_PATH=${PROTOC} \
		JAVA_HOME=${JAVA_HOME}

MAVEN_PROFILES=	dist native
MAVEN_ARGS=	-Dmaven.javadoc.skip=true -Dmaven.clean.skip=true \
		-Dmaven.repo.local=${WRKDIR}/m2 -DskipTests \
		-DprotocExecutable=${PROTOC} \
		-Dprotobuf.compiler.version=file://${PROTOC} \
		-Drequire.bzip2 \
		-Drequire.snappy -Dsnappy.prefix=${LOCALBASE} \
		-Drequire.zstd -Dzstd.prefix=${LOCALBASE} \
		-Drequire.openssl -Dopenssl.prefix=${OPENSSLBASE}

OPTIONS_DEFINE=		EXAMPLES FUSE YARNUI
OPTIONS_DEFINE_aarch64=	ISAL
OPTIONS_DEFINE_amd64=	ISAL
OPTIONS_DEFAULT=	FUSE
OPTIONS_DEFAULT_aarch64=	ISAL
OPTIONS_DEFAULT_amd64=	ISAL
OPTIONS_SUB=		yes

FUSE_DESC=	Build fuse_dfs to mount HDFS via FUSE
ISAL_DESC=	Use Intel ISA-L to accelerate erasure coding
YARNUI_DESC=	YARN Capacity Scheduler web UI (needs Node.js)

FUSE_USES=		fuse
FUSE_VARS=		MAVEN_ARGS+=-Drequire.fuse=true
ISAL_LIB_DEPENDS=	libisal.so:devel/isa-l
ISAL_VARS=		MAVEN_ARGS+="-Drequire.isal -Disal.prefix=${LOCALBASE}"
YARNUI_BUILD_DEPENDS=	npm:www/npm-node22
YARNUI_USES=		nodejs:22,build
YARNUI_VARS=		MAVEN_PROFILES+=yarn-ui

HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}
HDFS_NATIVE=	${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-native-client

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
	${MKDIR} ${PROTOC_TOOLS_SRC} ${PROTOC_TOOLS_BUILD} ${GRPC_PLUGIN_DIR}
	${INSTALL_DATA} ${FILESDIR}/protoc-tools.cmake ${PROTOC_TOOLS_SRC}/CMakeLists.txt
	cd ${PROTOC_TOOLS_BUILD} && ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER="${CC}" -DCMAKE_CXX_COMPILER="${CXX}" \
		-DCMAKE_PREFIX_PATH="${LOCALBASE}" \
		-DPROTOBUF_SRC=${WRKDIR}/protobuf-${PROTOBUF_VERSION} \
		-DGRPC_JAVA_SRC=${WRKDIR}/grpc-java-${GRPC_JAVA_VERSION} \
		${PROTOC_TOOLS_SRC}
	${CMAKE_BIN} --build ${PROTOC_TOOLS_BUILD} \
		--target protoc protoc-gen-grpc-java --parallel ${MAKE_JOBS_NUMBER}
	${LN} -sf ${PROTOC_TOOLS_BUILD}/protoc-gen-grpc-java ${GRPC_PLUGIN_DIR}/

# frontend-maven-plugin cannot download node for FreeBSD; the patched pom
# skips that step and expects node and npm where it would have put them.
pre-build-YARNUI-on:
	${MKDIR} ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-capacity-scheduler-ui/target/webapp/node/node_modules
	${LN} -sf ${LOCALBASE}/bin/node \
		${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-capacity-scheduler-ui/target/webapp/node/node
	${LN} -sf ${LOCALBASE}/lib/node_modules/npm \
		${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-capacity-scheduler-ui/target/webapp/node/node_modules/npm

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PATH=${GRPC_PLUGIN_DIR}:${PATH} \
		${LOCALBASE}/bin/mvn ${MAVEN_ARGS} -P${MAVEN_PROFILES:ts,} package

post-build:
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd

do-install:
	cd ${HADOOP_DIST}/bin && ${INSTALL_SCRIPT} hadoop hdfs mapred yarn ${STAGEDIR}${PREFIX}/bin/
	cd ${HADOOP_DIST} && ${COPYTREE_BIN} "libexec sbin" ${STAGEDIR}${PREFIX}/ "! -name *.cmd"
	cd ${HADOOP_DIST}/include && ${INSTALL_DATA} *h ${STAGEDIR}${PREFIX}/include/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hdfspp
	${INSTALL_DATA} ${HDFS_NATIVE}/src/main/native/libhdfspp/include/hdfspp/*.h \
		${STAGEDIR}${PREFIX}/include/hdfspp/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib/
.for lib in libhadoop.so.1.0.0 libhdfs.so.0.0.0 libhdfspp.so.0.1.0 libnativetask.so.1.0.0
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

post-install-FUSE-on:
	${INSTALL_PROGRAM} ${HDFS_NATIVE}/target/main/native/fuse-dfs/fuse_dfs ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

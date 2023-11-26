PORTNAME=	hadoop
PORTVERSION=	3.3.6
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/common/${PORTNAME}-${PORTVERSION}/ \
		http://archive.apache.org/dist/tomcat/tomcat-10/v${TOMCAT_VERSION}/bin/:tomcat

PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		apache-tomcat-${TOMCAT_VERSION}.tar.gz:tomcat
DIST_SUBDIR=	hadoop
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Apache Map/Reduce framework

LICENSE=	APACHE20

BUILD_DEPENDS=	ant:devel/apache-ant \
		bash:shells/bash \
		cmake:devel/cmake \
		mvn:devel/maven \
		protobuf>0:devel/protobuf
LIB_DEPENDS=	libprotobuf.so:devel/protobuf25 \
		libsasl2.so:security/cyrus-sasl2 \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash \
		setsid:sysutils/setsid

USES=		compiler:c++11-lang cpe pkgconfig shebangfix ssl
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	17
USE_LDCONFIG=	yes

SHEBANG_FILES=	hadoop-common-project/hadoop-kms/src/main/conf/kms-env.sh \
		hadoop-common-project/hadoop-kms/src/main/sbin/kms.sh \
		hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/conf/httpfs-env.sh \
		hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/sbin/httpfs.sh \
		hadoop-tools/hadoop-sls/src/main/bin/rumen2sls.sh \
		hadoop-tools/hadoop-sls/src/main/bin/slsrun.sh

CONFLICTS_INSTAL=	yarn

MAKE_ENV+=	HADOOP_PROTOC_PATH=${LOCALBASE}/bin/protoc \
		JAVA_HOME=${JAVA_HOME}
MAKE_ARGS+=	CXXFLAGS="${CXXFLAGS} -fPIC"

OPTIONS_DEFINE=	EXAMPLES

TOMCAT_VERSION=	10.1.0-M17
HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}

HADOOP_LOGDIR=	/var/log/hadoop
HADOOP_RUNDIR=	/var/run/hadoop

HDFS_USER=	hdfs
MAPRED_USER=	mapred
HADOOP_GROUP=	hadoop
USERS=		${HDFS_USER} ${MAPRED_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop-layout.sh httpfs-env.sh kms-env.sh
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
	${REINPLACE_CMD} -e "s#/bin/bash#${LOCALBASE}/bin/bash#" ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/MRJobConfig.java ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/containermanager/launcher/ContainerLaunch.java ${WRKSRC}/hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java ${WRKSRC}/hadoop-common-project/hadoop-common/src/main/bin/hadoop-daemon.sh
	${RM} ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/primitives.h

do-build:
	${MKDIR} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/downloads
	${MKDIR} ${WRKSRC}/hadoop-common-project/hadoop-kms/downloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/apache-tomcat-${TOMCAT_VERSION}.tar.gz ${WRKSRC}/hadoop-common-project/hadoop-kms/downloads/
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mvn  -Dmaven.javadoc.skip=true -Dmaven.clean.skip=true -Dmaven.repo.local=${WRKDIR}/m2 package \
	-Pdist,native -DskipTests -Drequire.snappy -Dsnappy.prefix=${LOCALBASE} -Drequire.openssl -Drequire.zstd -Dzstd.prefix=${LOCALBASE}

post-build:
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd

do-install:
	cd ${HADOOP_DIST}/bin && ${INSTALL_SCRIPT} hadoop hdfs mapred yarn ${STAGEDIR}${PREFIX}/bin/
	cd ${HADOOP_DIST} && ${COPYTREE_BIN} "libexec sbin" ${STAGEDIR}${PREFIX}/ "! -name *.cmd"
	cd ${HADOOP_DIST}/include && ${INSTALL_DATA} *h ${STAGEDIR}${PREFIX}/include/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} libhadoop.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libhadoop.so.1.0.0
	${LN} -sf libhadoop.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libhadoop.so
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} libnativetask.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libnativetask.so.1.0.0
	${LN} -sf libnativetask.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libnativetask.so
	cd ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-native-client/target/target/usr/local/lib/ && ${INSTALL_DATA} libhdfs.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libhdfs.so.0.0.0 && ${LN} -sf libhdfs.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libhdfs.so
	cd ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-native-client/target/main/native/libhdfspp/ && ${INSTALL_DATA} libhdfspp.so.0.1.0 ${STAGEDIR}${PREFIX}/lib/libhdfspp.so.0.1.0 && ${LN} -sf libhdfspp.so.0.1.0 ${STAGEDIR}${PREFIX}/lib/libhdfspp.so
	cd ${HADOOP_DIST}/share/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DATADIR}/ "! -name *-sources.jar -and ! -name sources"
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/conf
	cd ${HADOOP_DIST}/etc/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${EXAMPLESDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs/target/classes/hdfs-default.xml ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/target/classes/httpfs-default.xml ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-common/target/classes/yarn-default.xml ${WRKSRC}/hadoop-common-project/hadoop-common/target/classes/core-default.xml ${WRKSRC}/hadoop-tools/hadoop-distcp/target/classes/distcp-default.xml ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/target/classes/mapred-default.xml ${STAGEDIR}/${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/hadoop-layout.sh ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/httpfs-env.sh ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/kms-env.sh ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${HADOOP_DIST}/etc/hadoop/core-site.xml  ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${HADOOP_DIST}/etc/hadoop/log4j.properties ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

.include <bsd.port.mk>

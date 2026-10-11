PORTNAME=	geode
DISTVERSION=	2.0.3
CATEGORIES=	databases java
MASTER_SITES=	APACHE/${PORTNAME}/${DISTVERSION} \
		https://archive.apache.org/dist/${PORTNAME}/${DISTVERSION}/ \
		https://services.gradle.org/distributions/:gradle \
		https://github.com/Martinfx/FreeBSD-Ports/releases/download/${PORTNAME}-${DISTVERSION}-deps/:deps
DISTFILES=	apache-${PORTNAME}-${DISTVERSION}-src.tgz \
		gradle-${GRADLE_VERSION}-bin.zip:gradle
.if !defined(GEODE_MAKE_DEPS)
DISTFILES+=	${GEODE_DEPS}.tar.gz:deps
.endif

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	In-memory data grid and distributed data management platform
WWW=		https://geode.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	the Gradle build runs with a 3 GB heap

USES=		cpe java
CPE_VENDOR=	apache

# Geode 2.x targets Java 17, and Gradle ${GRADLE_VERSION}, the version its
# build is written for, does not run on anything newer.
JAVA_VERSION=	17

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${DISTVERSION}-src

# Gradle resolves dependencies from the network.  They come instead from
# ${GEODE_DEPS}.tar.gz, a Gradle module cache made by the make-gradle-deps
# target below and published as an asset of the ${PORTNAME}-${DISTVERSION}-deps
# release of this repository by .github/workflows/geode-gradle-deps.yml,
# and the build runs offline.
GEODE_DEPS=	${PORTNAME}-${DISTVERSION}-gradle-deps
GRADLE_VERSION=	7.3.3
GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/${GEODE_DEPS} \
		JAVA_HOME=${JAVA_HOME}
# -Pversion: a release build; without it the source tree builds
# ${DISTVERSION}-build.0.
GRADLE_ARGS=	--no-daemon --no-build-cache --no-watch-fs --console=plain \
		--max-workers=${MAKE_JOBS_NUMBER} -Duser.home=${WRKDIR} \
		-Pversion=${DISTVERSION}
GRADLE_CMD=	${SETENV} ${MAKE_ENV} ${GRADLE_ENV} \
		${SH} ${WRKDIR}/gradle-${GRADLE_VERSION}/bin/gradle ${GRADLE_ARGS}
GEODE_DIST=	${WRKSRC}/geode-assembly/build/install/apache-${PORTNAME}

USE_RC_SUBR=	geode_locator geode_server

# The geode user and group are not registered in the ports tree yet; they
# are taken from the UID 829/GID 829 slot listed as free in ${PORTSDIR}/UIDs
# and GIDs.  ${PORTSDIR}/UIDs and GIDs are searched first, so a registration
# there takes precedence over the files shipped with this port.
GEODE_USER=	geode
GEODE_GROUP=	geode
GEODE_DBDIR=	/var/db/geode
USERS=		${GEODE_USER}
GROUPS=		${GEODE_GROUP}
UID_FILES=	${PORTSDIR}/UIDs ${FILESDIR}/UIDs
GID_FILES=	${PORTSDIR}/GIDs ${FILESDIR}/GIDs

OPTIONS_DEFINE=	DOCS

PORTDOCS=	NOTICE README.md javadoc

# Named one by one: post-build leaves gemfire.properties.bak behind.
GEODE_CONFIG_FILES=	cache.xml gemfire.properties log4j2.xml \
			open-all-jdk-packages-linux-openjdk-17

SUB_FILES=	gemfire.properties.sample gfsh pkg-message
SUB_LIST=	GEODE_DBDIR=${GEODE_DBDIR} \
		GEODE_GROUP=${GEODE_GROUP} \
		GEODE_USER=${GEODE_USER} \
		JAVA_HOME=${JAVA_HOME} \
		VERSION=${DISTVERSION}
PLIST_SUB=	GEODE_DBDIR=${GEODE_DBDIR} \
		GEODE_GROUP=${GEODE_GROUP} \
		GEODE_USER=${GEODE_USER} \
		VERSION=${DISTVERSION}

.include <bsd.port.pre.mk>

# Gradle ships its native integration for FreeBSD on amd64 only.
.if ${ARCH} != amd64
GRADLE_ARGS+=	-Dorg.gradle.native=false
.endif

do-build:
	cd ${WRKSRC} && ${GRADLE_CMD} --offline :geode-assembly:installDist

# config/gemfire.properties is a dump of every property at its default
# value, generated during the build, so deploy-working-dir records the
# build directory instead of its real default, the member's working
# directory.
post-build:
	@${REINPLACE_CMD} -e '/^deploy-working-dir=/d' \
		${GEODE_DIST}/config/gemfire.properties

# Maintainer target: rebuild ${GEODE_DEPS}.tar.gz in ${DISTDIR} by running
# the build online from a clean tree, then "make makesum".
make-gradle-deps:
	@${MAKE} -C ${.CURDIR} clean
	@${MAKE} -C ${.CURDIR} GEODE_MAKE_DEPS=yes patch
	cd ${WRKSRC} && ${GRADLE_CMD} :geode-assembly:installDist
	cd ${WRKDIR}/${GEODE_DEPS}/caches && ${TAR} -czf \
		${DISTDIR}/${GEODE_DEPS}.tar.gz --uid 0 --gid 0 \
		--exclude '*.lock' --exclude gc.properties \
		-s ',^modules-2,${GEODE_DEPS}/caches/modules-2,' modules-2

# The upstream bin/gfsh is a bash script that guesses GEODE_HOME from $0; it
# is replaced by files/gfsh.in, installed in ${PREFIX}/bin and linked from
# ${DATADIR}/bin, where the Geode documentation expects to find it.
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/config \
		${STAGEDIR}${DATADIR}/extensions ${STAGEDIR}${DATADIR}/lib \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${GEODE_DBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/gfsh ${STAGEDIR}${PREFIX}/bin/gfsh
	${RLN} ${STAGEDIR}${PREFIX}/bin/gfsh ${STAGEDIR}${DATADIR}/bin/gfsh
	cd ${GEODE_DIST}/config && ${INSTALL_DATA} ${GEODE_CONFIG_FILES} \
		${STAGEDIR}${DATADIR}/config
	${INSTALL_DATA} ${GEODE_DIST}/lib/* ${STAGEDIR}${DATADIR}/lib
	cd ${GEODE_DIST} && ${COPYTREE_SHARE} tools ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/gemfire.properties.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${GEODE_DIST}/bin/gfsh-completion.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gfsh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${GEODE_DIST}/NOTICE ${GEODE_DIST}/README.md \
		${STAGEDIR}${DOCSDIR}
	cd ${GEODE_DIST} && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

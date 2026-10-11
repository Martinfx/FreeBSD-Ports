PORTNAME=	geode
DISTVERSION=	2.0.3
CATEGORIES=	databases java
MASTER_SITES=	APACHE/${PORTNAME}/${DISTVERSION} \
		https://archive.apache.org/dist/${PORTNAME}/${DISTVERSION}/
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	In-memory data grid and distributed data management platform
WWW=		https://geode.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe java
CPE_VENDOR=	apache

# Geode 2.x is built for Java 17 (class file version 61) and depends on
# Spring 6 and Jetty 12, which require Java 17 as well.
JAVA_VERSION=	17+

NO_ARCH=	yes
NO_BUILD=	yes

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

# Named one by one: post-patch leaves gemfire.properties.bak behind.
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

# config/gemfire.properties is a dump of every property at its default
# value, taken on the release manager's machine, so deploy-working-dir
# records a path from that machine instead of its real default, the
# member's working directory.
post-patch:
	@${REINPLACE_CMD} -e '/^deploy-working-dir=/d' \
		${WRKSRC}/config/gemfire.properties

# The upstream bin/gfsh is a bash script that guesses GEODE_HOME from $0; it
# is replaced by files/gfsh.in, installed in ${PREFIX}/bin and linked from
# ${DATADIR}/bin, where the Geode documentation expects to find it.
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/config \
		${STAGEDIR}${DATADIR}/extensions ${STAGEDIR}${DATADIR}/lib \
		${STAGEDIR}${ETCDIR} ${STAGEDIR}${GEODE_DBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/gfsh ${STAGEDIR}${PREFIX}/bin/gfsh
	${RLN} ${STAGEDIR}${PREFIX}/bin/gfsh ${STAGEDIR}${DATADIR}/bin/gfsh
	cd ${WRKSRC}/config && ${INSTALL_DATA} ${GEODE_CONFIG_FILES} \
		${STAGEDIR}${DATADIR}/config
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}/lib
	cd ${WRKSRC} && ${COPYTREE_SHARE} tools ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/gemfire.properties.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/bin/gfsh-completion.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/gfsh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

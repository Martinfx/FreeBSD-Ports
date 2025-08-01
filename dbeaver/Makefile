PORTNAME=	dbeaver
DISTVERSION=	25.1.3
CATEGORIES=	devel java
MASTER_SITES=	LOCAL/vvd:deps
DISTFILES=	${PORTNAME}-${PORTVERSION}-deps.tar.gz:deps

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Free universal database tool and SQL client.
WWW=		https://dbeaver.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	maven39>0:devel/maven39

USES=		java:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dbeaver
GH_PROJECT=	dbeaver
GH_TUPLE=	dbeaver:dbeaver-common:8be2658:dbeavercommon \
		dbeaver:dbeaver-jdbc-libsql:221cc34:jdbc

JAVA_VERSION=	21+
JAVA_VENDOR=	openjdk
SUB_FILES=	${PORTNAME} ${PORTNAME}.desktop
OFFLINE=	-o

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
MAVEN_ARCH=     x86_64
.elif ${ARCH} == "i386"
MAVEN_ARCH=     x86
.else
MAVEN_ARCH=	${ARCH}
.endif

MAVEN_ENV=	MAVEN_OPTS=-Xmx1024m  JAVA_HOME=${JAVA_HOME}
DBEAVER_PATH=	product/community/target/products/org.jkiss.dbeaver.core.product/freebsd/gtk/${MAVEN_ARCH}/dbeaver

pre-configure:
	${MV} ${WRKDIR}/dbeaver-common-8be2658 ${WRKDIR}/dbeaver-common
	${MV} ${WRKDIR}/dbeaver-jdbc-libsql-221cc34 ${WRKDIR}/dbeaver-jdbc-libsql

do-build:
	@cd ${WRKSRC}/product/aggregate && ${SETENV} ${MAVEN_ENV} ${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Dnative=gtk.freebsd.${MAVEN_ARCH} -T 1C -DskipTests verify \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC}/${DBEAVER_PATH} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/${DBEAVER_PATH}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/plugins/org.eclipse.equinox.launcher.gtk.freebsd.x86_64_1.2.1400.v20250607-0038/eclipse_11911.so
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/dbeaver
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s "share/dbeaver" -not -type d) >> ${TMPPLIST}
	@(cd ${STAGEDIR}${PREFIX}; ${FIND} -s -d "share/dbeaver" -type d -empty | ${SED} -ne 's,^,@dir ,p') >> ${TMPPLIST}
	${ECHO} "bin/${PORTNAME}" >> ${TMPPLIST}
	${ECHO} "share/applications/${PORTNAME}.desktop" >> ${TMPPLIST}

.include <bsd.port.post.mk>
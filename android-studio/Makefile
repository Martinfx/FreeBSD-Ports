PORTNAME=	android-studio
DISTVERSION=	2025.1.3.7
CATEGORIES=	devel linux
MASTER_SITES=	https://r1---sn-2gb7snez.gvt1.com/edgedl/android/studio/ide-zips/2025.1.3.7/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux
EXTRACT_SUFX=.tar.gz
MAINTAINER=	freebsd@sysctl.cz

COMMENT=	Official IDE for Android
WWW=		https://developer.android.com/studio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		java:run
JAVA_VERSION=	11
JAVA_VENDOR=	openjdk

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	LINUXBASE=${LINUXBASE}
INSTALL_TARGET=	install-strip

do-install:

	${MKDIR} ${STAGEDIR}${LINUXBASE}/android-studio
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LINUXBASE}/android-studio
	${CHMOD} +x ${STAGEDIR}${LINUXBASE}/android-studio/bin/studio.sh
	${INSTALL_DATA} ${WRKSRC}/bin/studio.png ${STAGEDIR}${PREFIX}/share/pixmaps/studio.png

.include <bsd.port.mk>


PORTNAME=	android-studio
DISTVERSION=	2023.2.1.25
CATEGORIES=	devel linux
MASTER_SITES=	https://redirector.gvt1.com/edgedl/android/studio/ide-zips/${DISTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux
MAINTAINER=	freebsd@sysctl.cz

COMMENT=	Official IDE for Android
WWW=		https://developer.android.com/studio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VERSION=	11
JAVA_VENDOR=	openjdk
JAVA_RUN=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	LINUXBASE=${LINUXBASE}
INSTALL_TARGET=	install-strip

do-install:

	${MKDIR} ${STAGEDIR}${LINUXBASE}/android-studio
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LINUXBASE}/android-studio
	${CHMOD} -R +x ${STAGEDIR}${LINUXBASE}/android-studio/
	${INSTALL_DATA} ${WRKSRC}/bin/studio.png ${STAGEDIR}${PREFIX}/share/pixmaps/studio.png

.include <bsd.port.mk>


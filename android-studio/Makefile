PORTNAME=	android-studio
DISTVERSION=	2020.3.1.24
CATEGORIES=	devel linux
MASTER_SITES=	https://redirector.gvt1.com/edgedl/android/studio/ide-zips/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux
MAINTAINER=	freebsd@sysctl.cz
COMMENT= 	Android Studio provides the fastest tools for building apps on every type of Android device.
WWW=		https://developer.android.com/studio/

LICENSE= 	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

#USES=		ssl
ONLY_FOR_ARCHS= amd64
USE_JAVA=	yes
JAVA_VENDOR=   	openjdk
JAVA_RUN=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	LINUXBASE=${LINUXBASE}

do-install:

	${MKDIR} ${STAGEDIR}${LINUXBASE}/android-studio
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LINUXBASE}/android-studio

.include <bsd.port.mk>

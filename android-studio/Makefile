PORTNAME=	android-studio
DISTVERSION=	2020.3.1.24
CATEGORIES=	devel
MASTER_SITES=	https://redirector.gvt1.com/edgedl/android/studio/ide-zips/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-linux
MAINTAINER=	freebsd@sysctl.cz
COMMENT= 	android studio

LICENSE= 	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VENDOR=   	openjdk
JAVA_RUN=	yes
#GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	JAVA_HOME=${JAVA_HOME}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>

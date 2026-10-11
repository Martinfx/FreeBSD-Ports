PORTNAME=	android-studio
DISTVERSION=	2026.2.1.8
CATEGORIES=	devel java linux
MASTER_SITES=	https://dl.google.com/dl/android/studio/ide-zips/${DISTVERSION}/ \
		https://edgedl.me.gvt1.com/android/studio/ide-zips/${DISTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${STUDIO_RELEASE}-linux
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official IDE for Android (Linux binary)
WWW=		https://developer.android.com/studio/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream only provides x86_64 Linux binaries

USES=		linux
USE_LINUX=	alsalib dbuslibs dri expat fontconfig freetype gtk3 xorglibs

NO_BUILD=	yes
# Upstream names the tarball after the release codename.
STUDIO_RELEASE=	rabbit1
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	android-studio.desktop android-studio.sh pkg-message
SUB_LIST=	LINUXBASE=${LINUXBASE}

PLIST_FILES=	bin/android-studio \
		share/applications/android-studio.desktop \
		share/pixmaps/android-studio.png \
		share/pixmaps/android-studio.svg

OPTIONS_DEFINE=		ADB FSNOTIFIER
OPTIONS_DEFAULT=	ADB

ADB_DESC=		Use native adb (devel/android-tools) for USB devices
ADB_RUN_DEPENDS=	adb:devel/android-tools
FSNOTIFIER_DESC=	Native file watcher (java/intellij-fsnotifier)
FSNOTIFIER_RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

post-patch:
# Chromium (JCEF) sandbox and GPU process do not work under the Linux ABI layer.
	@${PRINTF} '%s\n' \
		'-Dide.browser.jcef.sandbox.enable=false' \
		'-Dide.browser.jcef.gpu.disable=true' \
		>> ${WRKSRC}/bin/studio64.vmoptions

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
# COPYTREE_SHARE drops the executable bit, restore it for the JBR, launchers,
# helper binaries and native tools.
	cd ${STAGEDIR}${DATADIR} && (cd ${WRKSRC} && \
		${FIND} . -type f -perm -u+x -print0) | ${XARGS} -0 ${CHMOD} 755
	${INSTALL_SCRIPT} ${WRKDIR}/android-studio.sh \
		${STAGEDIR}${PREFIX}/bin/android-studio
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/android-studio.desktop ${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/bin/studio.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/android-studio.png
	${INSTALL_DATA} ${WRKSRC}/bin/studio.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/android-studio.svg

post-install:
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} \
		\( -type f -o -type l \) >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} -type d -empty | \
		${SED} -e 's|^|@dir |' >> ${TMPPLIST}

.include <bsd.port.mk>

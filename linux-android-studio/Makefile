PORTNAME=	android-studio
DISTVERSION=	2026.2.2.8
CATEGORIES=	devel java linux
MASTER_SITES=	https://dl.google.com/dl/android/studio/ide-zips/${DISTVERSION}/ \
		https://edgedl.me.gvt1.com/android/studio/ide-zips/${DISTVERSION}/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${STUDIO_RELEASE}-linux
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Official IDE for Android (Linux binary)
WWW=		https://developer.android.com/studio/

LICENSE=	ANDROID-STUDIO
LICENSE_NAME=	Android Software Development Kit License Agreement
LICENSE_TEXT=	See: https://developer.android.com/studio/terms
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell \
		auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	upstream only provides x86_64 Linux binaries

USES=		linux:rl9
USE_LINUX=	alsalib cups-libs dbuslibs dri fontconfig freetype gtk3 \
		libglvnd libxkbcommon wayland xorglibs

NO_BUILD=	yes
SUB_FILES=	android-studio.desktop android-studio.sh pkg-message
SUB_LIST=	LINUXBASE=${LINUXBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/android-studio \
		share/applications/android-studio.desktop \
		share/pixmaps/android-studio.png \
		share/pixmaps/android-studio.svg

OPTIONS_DEFINE=		ADB FSNOTIFIER
OPTIONS_DEFAULT=	ADB

ADB_DESC=		Native adb (devel/android-tools) for USB devices
FSNOTIFIER_DESC=	Native file watcher (java/intellij-fsnotifier)

ADB_RUN_DEPENDS=	adb:devel/android-tools
FSNOTIFIER_RUN_DEPENDS=	intellij-fsnotifier>0:java/intellij-fsnotifier

# Upstream names the tarball after the release codename.
STUDIO_RELEASE=	rabbit2

post-extract:
# Record the executables now: COPYTREE_SHARE hard links the staged files to
# WRKSRC (cpio -l) and its chmod 444 strips the bits in WRKSRC as well.
	cd ${WRKSRC} && ${FIND} . -type f -perm -u+x -print0 > ${WRKDIR}/.executables

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
# COPYTREE_SHARE drops the executable bit, restore it for the JBR, launchers,
# helper binaries and native tools.
	cd ${STAGEDIR}${DATADIR} && ${XARGS} -0 ${CHMOD} 755 < ${WRKDIR}/.executables
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
# Upstream ships the NDK debugger and clangd helpers with debug info.  The
# lldb-server binaries under lldb/android are device (Android) executables
# and stay as they are.
	${STRIP_CMD} \
		${STAGEDIR}${DATADIR}/plugins/android-ndk/resources/lldb/bin/LLDBFrontend \
		${STAGEDIR}${DATADIR}/plugins/android-ndk/resources/lldb/lib/libc++.so \
		${STAGEDIR}${DATADIR}/plugins/android-ndk/resources/lldb/lib64/libc++.so \
		${STAGEDIR}${DATADIR}/plugins/android-ndk/resources/lldb/lib64/libedit.so.0 \
		${STAGEDIR}${DATADIR}/plugins/cidr-clangd/bin/clang/linux/x64/bin/libc++.so
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} \
		\( -type f -o -type l \) >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL} -type d -empty | \
		${SED} -e 's|^|@dir |' >> ${TMPPLIST}

.include <bsd.port.mk>

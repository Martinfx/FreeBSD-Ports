PORTNAME=	amarok
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	audio kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player
WWW=		https://amarok.kde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

BUILD_DEPENDS=	libunwind>0:devel/libunwind \
		taglib>2.0.0:audio/taglib \
		libglvnd>0:graphics/libglvnd

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfftw3.so:math/fftw3 \
		liblastfm5.so:audio/liblastfm-qt5 \
		libqjson-qt5.so:devel/qjson \
		libtag.so:audio/taglib \
		liblz4.so:archivers/liblz4 \
		libunwind.so:devel/libunwind

USES=		cmake compiler:c++11-lang cpe desktop-file-utils \
		kde:${FLAVOR:S/qt//} mysql:client pkgconfig qca qt:${FLAVOR:S/qt//} shebangfix ssl xorg \
		gettext
USE_GL=		gl opengl
USE_QT=		${_USE_QT_${FLAVOR}}
USE_KDE=	${_USE_KDE_${FLAVOR}}
_USE_QT_qt5=	core concurrent declarative dbus gui location network \
		quickcontrols2 script scripttools sql svg webchannel \
		webengine widgets xml buildtools:build qmake:build testlib:build
_USE_QT_qt6=	base declarative positioning tools svg webchannel webengine 5compat
_USE_KDE_qt5=	archive auth attica bookmarks codecs config configwidgets \
		completion coreaddons crash dbusaddons dnssd globalaccel \
		 i18n iconthemes itemviews jobwidgets kdeclarative phonon \
		kcmutils kio kirigami2 newstuff notifications notifyconfig \
		package parts service solid sonnet texteditor textwidgets \
		threadweaver wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build syntaxhighlighting
_USE_KDE_qt6=	archive auth attica bookmarks codecs config configwidgets \
		completion coreaddons crash dbusaddons dnssd globalaccel \
		guiaddons i18n iconthemes itemviews jobwidgets kdeclarative \
		kcmutils kio kirigami2 newstuff notifications notifyconfig \
		package parts service solid sonnet texteditor textwidgets \
		threadweaver wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build syntaxhighlighting phonon \
		statusnotifieritem
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

CPE_VENDOR=	kde

KDE_INVENT=	a90438e9f1d7f0cc9d31ded9ad9d504d6cd50560 multimedia

CONFIGURE_ENV=	MYSQL_DIR=${LOCALBASE}

CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE}
_CMAKE_ON_qt5=	BUILD_WITH_QT5 WITH_DESKTOP_UI
_CMAKE_ON_qt6=	BUILD_WITH_QT6 WITH_DESKTOP_UI
_CMAKE_OFF_qt5=	BUILD_WITH_QT6
_CMAKE_OFF_qt6=	BUILD_WITH_QT5

OPTIONS_DEFINE=		IPOD MP3TUNES GPODDER LASTFM UTILITES PLAYER
OPTIONS_DEFAULT=	IPOD MP3TUNES GPODDER LASTFM UTILITES PLAYER
OPTIONS_SUB=		yes

IPOD_DESC=		Apple iPod support
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IPOD_USE=		GNOME=gdkpixbuf2,glib20
IPOD_USES=		gnome
IPOD_CMAKE_BOOL=	WITH_IPOD

MP3TUNES_DESC=		MP3tunes support
MP3TUNES_LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth \
			libcurl.so:ftp/curl
MP3TUNES_LIB_DEPENDS_OFF=	libgcrypt.so:security/libgcrypt
MP3TUNES_USE=		GNOME=glib20,libxml2
MP3TUNES_USES=		gnome
MP3TUNES_CMAKE_BOOL=	WITH_MP3Tunes

GPODDER_DESC=		Enable gpodder.net support
GPODDER_CMAKE_BOOL=	WITH_GPODDER

LASTFM_DESC=		Enable last.fm support
LASTFM_CMAKE_BOOL=    	WITH_LASTFM

UTILITES_DESC=		Enable building of utilities
UTILITES_CMAKE_BOOL=	WITH_UTILITIES

PLAYER_DESC=		Enable building of main Amarok player
PLAYER_CMAKE_BOOL=	WITH_PLAYER

PLIST=		${.CURDIR}/pkg-plist.${FLAVOR}
PLIST_SUB=	QT5_ONLY=${_QT5_ONLY_${FLAVOR}} \
		QT_VER=${FLAVOR:S/qt//} \
		SHLIB_VER=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>

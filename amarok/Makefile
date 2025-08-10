PORTNAME=	amarok
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.1
CATEGORIES=	audio kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE music player
WWW=		https://amarok.kde.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libunwind>0:devel/libunwind \
		taglib>2.0.0:audio/taglib \
		libglvnd>0:graphics/libglvnd \
		mariadb118-server>0:databases/mariadb118-server

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfftw3.so:math/fftw3 \
		liblastfm6.so:audio/liblastfm \
		libmtp.so:multimedia/libmtp \
		libtag.so:audio/taglib \
		libunwind.so:devel/libunwind \
		libmariadb.so:databases/mariadb106-client \
		libmariadb.so:databases/mariadb-connector-c

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext gl \
		kde:6 mysql:client pkgconfig qt:6 shared-mime-info ssl xorg

CPE_VENDOR=	kde

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

USE_GL+=	gl opengl
USE_KDE=	archive bookmarks codecs colorscheme config configwidgets \
		completion coreaddons crash dbusaddons dnssd doctools:build \
		ecm:build globalaccel guiaddons i18n iconthemes itemviews \
		jobwidgets kdeclarative kcmutils kio kirigami2 notifications \
		notifyconfig package parts phonon phonon-vlc service \
		solid sonnet statusnotifieritem syntaxhighlighting texteditor \
		textwidgets threadweaver wallet widgetsaddons windowsystem xmlgui
USE_LDCONFIG=	yes
USE_QT=		base declarative positioning tools svg webchannel webengine 5compat
USE_XORG=	ice sm x11 xext

CMAKE_ARGS=	-DOPENSSL_ROOT_DIR=${OPENSSLBASE}
CMAKE_ON=	WITH_DESKTOP_UI BUILD_WITH_QT6 WITHOUT_EMBEDDED_DB
CMAKE_OFF=	MYSQL_EMBEDDED WITH_EMBEDDED USE_EMBEDDED WITH_MARIADB_EMBEDDED

#CONFIGURE_ENV=	MYSQL_DIR=${LOCALBASE}

OPTIONS_DEFINE=		IPOD MP3TUNES GPODDER LASTFM UTILITES PLAYER
OPTIONS_DEFAULT=	IPOD MP3TUNES GPODDER LASTFM UTILITES PLAYER
OPTIONS_SUB=		yes

GPODDER_DESC=		Enable gpodder.net support
IPOD_DESC=		Apple iPod support
LASTFM_DESC=		Enable last.fm support
MP3TUNES_DESC=		MP3tunes support
PLAYER_DESC=		Enable building of main Amarok player
UTILITES_DESC=		Enable building of utilities

GPODDER_CMAKE_BOOL=	WITH_GPODDER
IPOD_LIB_DEPENDS=	libgpod.so:audio/libgpod \
			libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IPOD_USES=		gnome
IPOD_USE=		GNOME=gdkpixbuf,glib20
IPOD_CMAKE_BOOL=	WITH_IPOD
LASTFM_CMAKE_BOOL=	WITH_LASTFM
MP3TUNES_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libloudmouth-1.so:net-im/loudmouth
MP3TUNES_LIB_DEPENDS_OFF=	libgcrypt.so:security/libgcrypt
MP3TUNES_USES=		gnome
MP3TUNES_USE=		GNOME=glib20,libxml2
MP3TUNES_CMAKE_BOOL=	WITH_MP3Tunes
PLAYER_CMAKE_BOOL=	WITH_PLAYER
UTILITES_CMAKE_BOOL=	WITH_UTILITIES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		${WRKSRC}/cmake/modules/FindLoudmouth.cmake

.include <bsd.port.mk>

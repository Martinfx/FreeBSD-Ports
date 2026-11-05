PORTNAME=	onlyoffice
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0.0
CATEGORIES=	editors
# The v8 archive is the one of www/onlyoffice-documentserver.  It is gone
# from LOCAL/mikael, the copy of the package builders is on distcache, in
# the distfiles backup without a subdirectory.  The npm cache archive is
# made with files/make-npm-cache-archive.sh (see the comments there).
MASTER_SITES=	LOCAL/mikael/v8/:v8 \
		http://distcache.FreeBSD.org/ports-distfiles/:v8 \
		https://raw.githubusercontent.com/Martinfx/FreeBSD-Ports/onlyoffice-distfiles/onlyoffice/:npmcache
DISTFILES=	v8-8.9.255.25_all.tar.gz:v8 \
		${_NPM_CACHE_PARTS:S/$/:npmcache/}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${_DISTFILES:N${_NPM_CACHE}.*}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Office suite with document, spreadsheet and presentation editors
WWW=		https://www.onlyoffice.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and arm64, www/cef the same

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		gn:devel/gn \
		ninja:devel/ninja \
		npm:www/npm${NODEJS_SUFFIX} \
		optipng:graphics/optipng
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libcef.so:www/cef \
		libcups.so:print/cups \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libicuuc.so:devel/icu \
		libnotify.so:devel/libnotify \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils dos2unix gl gmake gnome iconv:wchar_t \
		java:build localbase nodejs:build pkgconfig python:build qt:5 \
		ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DesktopEditors
# The third party sources that the build scripts of core clone (at the
# commits they check out) are fetched as tuples instead
GH_TUPLE=	ONLYOFFICE:core:${_DS_TAGNAME}:core/core \
		ONLYOFFICE:desktop-apps:${_DS_TAGNAME}:apps/desktop-apps \
		ONLYOFFICE:desktop-sdk:${_DS_TAGNAME}:sdk/desktop-sdk \
		ONLYOFFICE:core-fonts:${_DS_TAGNAME}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:${_DS_TAGNAME}:dictionaries/dictionaries \
		ONLYOFFICE:document-templates:${_DS_TAGNAME}:dt/document-templates \
		ONLYOFFICE:sdkjs:${_DS_TAGNAME}:sdkjs/sdkjs \
		ONLYOFFICE:web-apps:${_DS_TAGNAME}:webapps/web-apps \
		ONLYOFFICE:build_tools:${_DS_TAGNAME}:buildtools/build_tools \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		chromiumembedded:cef:${_CEF_COMMIT}:cef/desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser \
		google:brotli:a47d747:google_brotli/core/Common/3dParty/brotli/brotli \
		GNOME:libxml2:39b66eb2089f491eacf8e22a7965a235f7f5735e:gnome_libxml2/core/Common/3dParty/libxml/libxml2 \
		hunspell:hunspell:8a2fdfe5a6bb1cbafc04b0c8486abcefd17ad903:hunspell_hunspell/core/Common/3dParty/hunspell/hunspell \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c

USE_GL=		gl
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_QT=		core dbus gui multimedia network printsupport svg widgets \
		x11extras buildtools:build qmake:build
USE_XORG=	x11 xcb

JAVA_VERSION=	11+

# The web-apps and start page (desktop-apps/common/loginpage, three vite
# projects) builds install their npm modules offline, from an npm cache
# that is a distfile: files/make-npm-cache-archive.sh fills it by running
# the same "npm install" commands with network access, for FreeBSD on
# amd64 and arm64.  The build never contacts the npm registry: when npm
# fails with "cache mode is 'only-if-cached' but no cached response is
# available", the URL in the message tells what the cache lacks, a
# tarball (regenerate the cache) or the metadata of a package (a lockfile
# is missing or does not match its package.json any more, see below).
#
# The cache holds the registry metadata in the form the npm which built
# it asked for, which depends on the npm version, so each "npm install"
# must be driven by a lockfileVersion 3 lockfile, which resolves
# everything from the tarballs in the cache.  web-apps has one, the start
# page projects have none, they get files/loginpage-*-package-lock.json.
_NPM_CACHE=	${PORTNAME}-${DISTVERSION}-npm-cache.tar.xz
# The archive is split in parts below the GitHub file size limit
_NPM_CACHE_PARTS=	${_NPM_CACHE}.00

_DS_BUILD=	176
_DS_TAGNAME=	${DISTVERSIONPREFIX}${DISTVERSION}.${_DS_BUILD}

# The editors are built on the cefclient sources of the CEF release that
# www/cef is built from.  Keep this in sync with CEF_COMMIT in www/cef.
_CEF_COMMIT=	708dc140cbc3286826a8abef89dc23a44ff9ea72

# These files have DOS line endings and are patched
DOS2UNIX_FILES=	core/DesktopEditor/agg-2.4/include/agg_math.h \
		core/DesktopEditor/agg-2.4/include/agg_span_gradient.h \
		core/DesktopEditor/common/Types.h \
		core/DesktopEditor/cximage/CxImage/ximage.h \
		core/DesktopEditor/cximage/CxImage/ximagif.cpp \
		core/DesktopEditor/cximage/CxImage/ximainfo.cpp \
		core/DesktopEditor/cximage/CxImage/ximajas.h \
		core/DesktopEditor/cximage/CxImage/ximajpg.cpp \
		core/DesktopEditor/cximage/CxImage/ximajpg.h \
		core/DesktopEditor/cximage/CxImage/ximaraw.cpp \
		core/DesktopEditor/cximage/raw/libdcr.h \
		core/DesktopEditor/doctrenderer/nativecontrol.h \
		core/DesktopEditor/graphics/Graphics.cpp \
		core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h \
		core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h \
		core/DjVuFile/libdjvu/DjVuDocument.cpp \
		core/HtmlFile/HtmlFile.cpp \
		core/UnicodeConverter/UnicodeConverter.cpp \
		desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib.pri

MAKE_ENV=	BUILD_NUMBER=${_DS_BUILD} \
		NODE_OPTIONS=--max-old-space-size=4096 \
		npm_package_config_node_gyp_nodedir=${LOCALBASE} \
		npm_package_config_node_gyp_python=${PYTHON_CMD} \
		PRODUCT_VERSION=${DISTVERSION} \
		PYTHON=${PYTHON_CMD} \
		PYTHONDONTWRITEBYTECODE=1

BINARY_ALIAS=	python=${PYTHON_CMD} \
		strip=true

# The build_tools deploy step lays the application out like the Linux
# packages do in /opt/onlyoffice/desktopeditors
APPDIR=		lib/${PORTNAME}/desktopeditors
_DEPLOYDIR=	${WRKSRC}/build_tools/out/freebsd_64/onlyoffice/desktopeditors
_LINUXPKG=	${WRKSRC}/desktop-apps/package/common/linux
_LOGINPAGE=	${WRKSRC}/desktop-apps/common/loginpage
_ICON_SIZES=	16 24 32 48 64 128 256

SUB_FILES=	onlyoffice-desktopeditors
SUB_LIST=	APPDIR=${PREFIX}/${APPDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT}
# lightningcss, which the start page minifies its CSS with, has no native
# module for FreeBSD/arm64: let vite use its default (esbuild) there
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aarch64-loginpage-vite
.endif

post-extract:
	@${MV} ${WRKDIR}/v8 ${WRKSRC}/core/Common/3dParty/v8_89

	@${MKDIR} ${WRKDIR}/.npm
	@${CAT} ${DISTDIR}/${DIST_SUBDIR}/${_NPM_CACHE}.0[0-9] | \
		${TAR} -xJf - -C ${WRKDIR}/.npm

	@${MKDIR} ${WRKSRC}/sdkjs-plugins/v1
	@${CP} ${WRKSRC}/onlyoffice.github.io/sdkjs-plugins/v1/* ${WRKSRC}/sdkjs-plugins/v1

# CEF for FreeBSD comes from www/cef, see files/cef_base_freebsd.pri
	@${MKDIR} ${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/cef_pri_freebsd
	${CP} ${FILESDIR}/cef_base_freebsd.pri \
		${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/cef_pri_freebsd/cef_base.pri
	${CP} ${FILESDIR}/cef_client_freebsd.pri \
		${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/cef_pri_freebsd/cef_client.pri
	${CP} ${FILESDIR}/cef_compat.h \
		${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/src/cefwrapper/

post-patch:
# See the comment above _NPM_CACHE
	${CP} ${FILESDIR}/loginpage-package-lock.json ${_LOGINPAGE}/package-lock.json
	${CP} ${FILESDIR}/loginpage-addondialog-package-lock.json ${_LOGINPAGE}/addondialog/package-lock.json
	${CP} ${FILESDIR}/loginpage-noconnect-package-lock.json ${_LOGINPAGE}/noconnect/package-lock.json

pre-configure:
	@${REINPLACE_CMD} -e 's|%%QT_ARCHDIR%%|${LOCALBASE}/${QT_ARCHDIR_REL}|' \
		-e 's|%%QT_VERSION%%|${QT5_VERSION}|' \
		${WRKSRC}/build_tools/tools/freebsd/automate.py
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/core/Apple/IWork.pro \
		${WRKSRC}/core/Common/3dParty/boost/boost.pri \
		${WRKSRC}/core/Common/3dParty/heif/heif.pri \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/buildtools/third_party/libc++/BUILD.gn \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp \
		${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/cef_pri_freebsd/cef_base.pri \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%OPENSSL_LIB%%|${OPENSSLLIB}|' \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig

	@${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni
	@${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni

do-build:
	${INSTALL_SCRIPT} ${FILESDIR}/npm ${BINARY_LINKDIR}/npm
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%WRKDIR%%|${WRKDIR}|g' ${BINARY_LINKDIR}/npm

# optipng-bin downloads a binary when installed, patch it to use the one of
# graphics/optipng instead (web-apps/build/patches)
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install optipng-bin@5.1.0
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	cd ${WRKSRC}/build_tools/tools/freebsd ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} automate.py desktop

# Desktop entry from the template of the Linux packages
	/usr/bin/m4 -I ${_LINUXPKG} \
		-D M4_DESKTOPEDITORS_EXEC=onlyoffice-desktopeditors \
		-D M4_SCHEME_HANDLER=oo-office \
		${_LINUXPKG}/desktopeditors.desktop.m4 | \
		${SED} 's|/usr/bin/|${PREFIX}/bin/|' > ${WRKDIR}/onlyoffice-desktopeditors.desktop

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APPDIR}
	cd ${_DEPLOYDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${APPDIR}
	cd ${STAGEDIR}${PREFIX}/${APPDIR} && ${FIND} . -type f \
		\( -name '*.so' -o -name '*.so.*' -o -name DesktopEditors \
		-o -name editors_helper -o -name x2t \) \
		-exec ${CHMOD} ${BINMODE} {} + -exec ${STRIP_CMD} {} +
	${INSTALL_SCRIPT} ${WRKDIR}/onlyoffice-desktopeditors ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKDIR}/onlyoffice-desktopeditors.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for s in ${_ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${_LINUXPKG}/icons/${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/onlyoffice-desktopeditors.png
.endfor

# The application directory holds thousands of files (the editors, fonts,
# dictionaries and plugins), list them when they are staged.
post-install:
	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${APPDIR} \( -type f -o -type l \) | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.post.mk>

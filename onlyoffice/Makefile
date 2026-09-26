PORTNAME=	onlyoffice
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.4
CATEGORIES=	editors
MASTER_SITES=	LOCAL/mikael/v8/:v8 \
		https://registry.npmjs.org/:npm
DISTFILES=	v8-8.9.255.25_all.tar.gz:v8 \
		${_NPM_DISTFILES:S/$/:npm/}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${_DISTFILES:N*.tgz}

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
		npm:www/npm-node20 \
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
		libicuuc.so:devel/icu \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		xdg-open:devel/xdg-utils

USES=		desktop-file-utils dos2unix gl gmake gnome iconv:wchar_t \
		java:build localbase pkgconfig python:build qt:5 ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DesktopEditors
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
		hunspell:hunspell:8a2fdfe5a6bb1cbafc04b0c8486abcefd17ad903:hunspell_hunspell/core/Common/3dParty/hunspell/hunspell \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c \
		fsbruva:onlyoffice-DS-npm-cache:${_DS_TAGNAME}-20250831:npm_cache/

USE_GL=		gl
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_QT=		core dbus gui multimedia network printsupport svg widgets \
		x11extras buildtools:build qmake:build
USE_XORG=	x11 xcb

JAVA_VERSION=	11+

# The web-apps, sdkjs and start page (desktop-apps/common/loginpage) builds
# install their npm modules offline, from the Document Server npm cache
# (the npm_cache tuple) and the packages below, which only the start page
# needs and which are added to that cache at the start of do-build.
_NPM_DISTFILES=	@babel/code-frame/-/code-frame-7.23.5.tgz \
		@babel/generator/-/generator-7.23.6.tgz \
		@babel/highlight/-/highlight-7.23.4.tgz \
		@babel/parser/-/parser-7.24.0.tgz \
		@babel/template/-/template-7.24.0.tgz \
		@babel/traverse/-/traverse-7.24.0.tgz \
		@babel/types/-/types-7.24.0.tgz \
		aws4/-/aws4-1.13.2.tgz \
		caniuse-lite/-/caniuse-lite-1.0.30001594.tgz \
		chokidar/-/chokidar-3.6.0.tgz \
		electron-to-chromium/-/electron-to-chromium-1.4.692.tgz \
		hasown/-/hasown-2.0.1.tgz \
		mkdirp/-/mkdirp-1.0.4.tgz \
		psl/-/psl-1.15.0.tgz \
		spritesmith/-/spritesmith-3.5.1.tgz \
		tough-cookie/-/tough-cookie-4.1.3.tgz \
		typedarray/-/typedarray-0.0.7.tgz \
		universalify/-/universalify-0.2.0.tgz

_DS_BUILD=	50
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
		core/DesktopEditor/xml/libxml2/trionan.c \
		core/DesktopEditor/xml/libxml2/xmlIO.c \
		core/DjVuFile/libdjvu/DjVuDocument.cpp \
		core/HtmlFile/HtmlFile.cpp \
		core/UnicodeConverter/UnicodeConverter.cpp \
		core/UnicodeConverter/UnicodeConverter.pro \
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
_LINUXPKG=	${WRKSRC}/desktop-apps/win-linux/package/linux
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
.endif

post-extract:
	@${MV} ${WRKDIR}/v8 ${WRKSRC}/core/Common/3dParty/v8_89

	@${LN} -s ${WRKSRC_npm_cache} ${WRKDIR}/.npm

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

pre-configure:
	@${REINPLACE_CMD} -e 's|%%QT_ARCHDIR%%|${LOCALBASE}/${QT_ARCHDIR_REL}|' \
		-e 's|%%QT_VERSION%%|${QT5_VERSION}|' \
		${WRKSRC}/build_tools/tools/freebsd/automate.py
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/core/Apple/IWork.pro \
		${WRKSRC}/core/Common/3dParty/boost/boost.pri \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/buildtools/third_party/libc++/BUILD.gn \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp \
		${WRKSRC}/desktop-sdk/ChromiumBasedEditors/lib/cef_pri_freebsd/cef_base.pri \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py
	@${REINPLACE_CMD} 's|%%OPENSSL_LIB%%|${OPENSSLLIB}|' \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig

	@${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni
	@${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni

do-build:
# npm is a build dependency, so this cannot be done in post-extract
.for f in ${_NPM_DISTFILES}
	@${SETENV} HOME=${WRKDIR} ${LOCALBASE}/bin/npm cache add --offline \
		${DISTDIR}/${DIST_SUBDIR}/${f} > /dev/null
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/npm ${BINARY_LINKDIR}/npm
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${BINARY_LINKDIR}/npm

	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install optipng-bin@5.1.0
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	@cd ${WRKSRC}/sdkjs ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/sdkjs ; ${SETENV} ${MAKE_ENV} npm install grunt

	cd ${WRKSRC}/build_tools/tools/freebsd ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} automate.py desktop

# Desktop entry from the template of the Linux packages
	/usr/bin/m4 -I ${_LINUXPKG}/common -D M4_COMPANY_NAME=ONLYOFFICE \
		-D M4_DESKTOPEDITORS_EXEC=onlyoffice-desktopeditors \
		-D M4_SCHEME_HANDLER=oo-office \
		${_LINUXPKG}/common/desktopeditors.desktop.m4 | \
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
	${INSTALL_DATA} ${_LINUXPKG}/common/icons/${s}x${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/onlyoffice-desktopeditors.png
.endfor

# The application directory holds thousands of files (the editors, fonts,
# dictionaries and plugins), list them when they are staged.
post-install:
	@cd ${STAGEDIR}${PREFIX} && ${FIND} ${APPDIR} \( -type f -o -type l \) | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.post.mk>

PORTNAME=	onlyoffice
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.4
MASTER_SITES+=	LOCAL/mikael/v8/:source1 \
		https://nodejs.org/dist/v${PKGFETCH_NODE_VERSION}/:source3
DISTFILES+=	v8-8.9.255.25_all.tar.gz:source1 \
		node-v${PKGFETCH_NODE_VERSION}.tar.gz:source3
CATEGORIES=	www

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	onlyoffice desktop editors
WWW=		https://www.onlyoffice.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_SSL=	boringssl libressl libressl-devel
BROKEN_SSL_REASON=	Node.js requires OpenSSL
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and arm64

PKGFETCH_NODE_VERSION=	20.19.4
DS_BUILD=	50

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs \
		glib>=2.54:devel/glib20 \
		gn:devel/gn \
		java:java/openjdk11 \
		ninja:devel/ninja \
		npm:www/npm-node20

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libcurl.so:ftp/curl \
		libharfbuzz.so:print/harfbuzz \
		libiconv.so:converters/libiconv \
		libicuuc.so:devel/icu \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>0:sysutils/py-supervisor@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		gsed:textproc/gsed \
		pwgen:sysutils/pwgen \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv localbase pkgconfig \
		python:3.9+,build qt:5 ssl trigger

USE_LDCONFIG=	yes
USE_QT=		qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DesktopEditors
DS_TAGNAME=	${DISTVERSIONPREFIX}${DISTVERSION}.${DS_BUILD}
GH_TUPLE=	ONLYOFFICE:core:${DS_TAGNAME}:core/core \
		ONLYOFFICE:core-fonts:${DS_TAGNAME}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:${DS_TAGNAME}:dictionaries/dictionaries \
		ONLYOFFICE:sdkjs:${DS_TAGNAME}:sdkjs/sdkjs \
		ONLYOFFICE:web-apps:${DS_TAGNAME}:webapps/web-apps \
		ONLYOFFICE:build_tools:${DS_TAGNAME}:buildtools/build_tools \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser \
		google:brotli:a47d747:google_brotli/core/Common/3dParty/brotli/brotli \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c \
		fsbruva:onlyoffice-DS-pkg-cache:v${PKGFETCH_NODE_VERSION}:pkg_cache/ \
		fsbruva:onlyoffice-DS-npm-cache:${DS_TAGNAME}-20250831:npm_cache/

MAKE_ENV=	BUILD_NUMBER=${DS_BUILD} \
		npm_package_config_node_gyp_nodedir=${LOCALBASE} \
		npm_package_config_node_gyp_python=${PYTHON_CMD} \
		PKG_CACHE_PATH=${WRKDIR}/.pkg-cache \
		PRODUCT_VERSION=${DISTVERSION} \
		PYTHON=${PYTHON_CMD}

BINARY_ALIAS=	python=${PYTHON_CMD} \
		strip=true

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
	@${LN} -s ${WRKSRC_pkg_cache} ${WRKDIR}/.pkg-cache
	@${CP} ${DISTDIR}/node-v${PKGFETCH_NODE_VERSION}.tar.gz ${WRKDIR}/.pkg-cache/node

	@${MKDIR} ${WRKSRC}/sdkjs-plugins/v1
	@${CP} ${WRKSRC}/onlyoffice.github.io/sdkjs-plugins/v1/* ${WRKSRC}/sdkjs-plugins/v1


pre-configure:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/build_tools/tools/freebsd/automate.py \
		${WRKSRC}/core/Apple/IWork.pro \
		${WRKSRC}/core/Common/3dParty/boost/boost.pri \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/buildtools/third_party/libc++/BUILD.gn \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp 
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py \
		${WRKSRC}/build_tools/scripts/build_server.py 
	@${REINPLACE_CMD} 's|%%PKGFETCH_NODE_MAJOR_VERSION%%|${PKGFETCH_NODE_VERSION:C/^([0-9]+)\..*/\1/}|' \
		${WRKSRC}/build_tools/scripts/build_server.py
	@${REINPLACE_CMD} 's|%%DISTDIR%%|${DISTDIR}|' \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} 's|%%OPENSSL_LIB%%|${OPENSSLLIB}|' \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri

	@${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni
	@${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni

do-build:
	${INSTALL_SCRIPT} ${FILESDIR}/npm ${BINARY_LINKDIR}/npm
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKDIR}/.bin/npm

	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install optipng-bin@5.1.0
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt

	@${MKDIR} ${WRKSRC}/yao-pkg
	@${CP} ${FILESDIR}/package* ${WRKSRC}/yao-pkg
	@cd ${WRKSRC}/yao-pkg ; ${SETENV} ${MAKE_ENV} npm install @yao-pkg/pkg@6.6.0

	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_lib-es5_build.js || ${TRUE}
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_patches_node.v${PKGFETCH_NODE_VERSION}.cpp.patch || ${TRUE}

	cd ${WRKSRC}/build_tools/tools/freebsd ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} automate.py desktop

do-install:


.include <bsd.port.post.mk>

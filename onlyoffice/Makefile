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
		nginx:www/nginx \
		pwgen:sysutils/pwgen \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv localbase pkgconfig \
		python:3.9+,build qt:5 ssl trigger

USE_LDCONFIG=	yes
USE_QT=	qmake:build

USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DesktopEditors
GH_TUPLE=	ONLYOFFICE:core:bc96c82:core/core \
		ONLYOFFICE:core-fonts:7030c66:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:d3223bb:dictionaries/dictionaries \
		ONLYOFFICE:sdkjs:34d1a1e:sdkjs/sdkjs \
		ONLYOFFICE:web-apps:0e5d9fd:webapps/web-apps \
		ONLYOFFICE:build_tools:2ffc1b9:buildtools/build_tools \
		ONLYOFFICE:DocumentBuilder:626d1e44db3d06ceb8298215a67ef0475912d89a:document_builder/DocumentBuilder \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser \
		google:brotli:a47d747:google_brotli/core/Common/3dParty/brotli/brotli \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c
#		fsbruva:onlyoffice-DS-pkg-cache:v${PKGFETCH_NODE_VERSION}:pkg_cache/ \
#		fsbruva:onlyoffice-DS-npm-cache:${DS_TAGNAME}-20250831:npm_cache/

MAKE_ENV=	BUILD_NUMBER=50 \
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

	#@${LN} -s ${WRKSRC_npm_cache} ${WRKDIR}/.npm
	#@${LN} -s ${WRKSRC_pkg_cache} ${WRKDIR}/.pkg-cache
	#@${CP} ${DISTDIR}/node-v${PKGFETCH_NODE_VERSION}.tar.gz ${WRKDIR}/.pkg-cache/node

	@${MKDIR} ${WRKSRC}/sdkjs-plugins/v1
	@${CP} ${WRKSRC}/onlyoffice.github.io/sdkjs-plugins/v1/* ${WRKSRC}/sdkjs-plugins/v1

do-install:


.include <bsd.port.post.mk>
PORTNAME=	xmake
DISTVERSIONPREFIX=v
DISTVERSION=	2.9.2
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	A cross-platform build utility based on Lua.
WWW=		https://xmake.io/#/

LICENSE=	APACHE20
LICENSE_FILE=   ${WRKSRC}/LICENSE.md

USES=		compiler:c++17-lang gmake
USE_GITHUB=     yes
GH_ACCOUNT=     xmake-io
GH_PROJECT=     xmake
GH_TUPLE+=	xmake-io:xmake-core-lua-cjson:ddcecf3b24b71421e7b4a2962f1fbcc0297e0c1e:xmakecoreluacjson/core/src/lua-cjson/lua-cjson \
		xmake-io:xmake-core-lua:eadd8c7178c79c814ecca9652973a9b9dd4cc71b:xmakecorelua/core/src/lua/lua \
		xmake-io:xmake-core-luajit:7cdc078416037cd0a16a79553509a7f153fe629d:xmakecoreluajit/core/src/luajit/luajit \
		xmake-io:xmake-core-lz4:033606ef259ef2852f6ae1e8ec7a10c641417654:xmakecorelz4/core/src/lz4/lz4 \
		xmake-io:xmake-core-pdcurses:5c62af03e9a05e3a3ae8c8354c1234b772dcf4b0:xmakecorepdcurses/core/src/pdcurses/pdcurses \
		xmake-io:xmake-core-sv:b3363a3cb2f499a735eaebe87a8a3491593e3289:xmakecoresv/core/src/sv/sv \
		tboox:tbox:36c7364:tbox/core/src/tbox/tbox

do-build:
	@cd ${WRKSRC} && ./configure --ninja=ninja --prefix=${PREFIX}
	@cd ${WRKSRC} && gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xmake
	@cd ${WRKSRC}/xmake/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${PREFIX}/share/xmake

.include <bsd.port.mk>

PORTNAME=	natron
DISTVERSION=	2.6.0.a20261116
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Node-graph based compositing software
WWW=		https://natrongithub.github.io/

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}shiboken6-tools>0:devel/shiboken6-tools@${PY_FLAVOR}
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libpyside6.abi3.so:devel/pyside6@${PY_FLAVOR} \
		libshiboken6.abi3.so:devel/shiboken6@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
		${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase \
		pkgconfig python qt:6 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
# branch RB-2.6
GH_TAGNAME=	2303d45c11cccf7a4e1745142867cead96baa7b8
GH_TUPLE=	NatronGitHub:openfx:4476791d0618ef381ca58d8ac4057c26f1b32dae:openfx/libs/OpenFX \
		NatronGitHub:SequenceParsing:3c93fcc488632b0bdfeee3181586809932357598:SequenceParsing/libs/SequenceParsing \
		NatronGitHub:tinydir:64fb1d4376d7580aa1013fdbacddbbeba67bb085:tinydir/libs/SequenceParsing/tinydir
USE_GL=		gl
USE_QT=		5compat base
USE_XORG=	x11

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD}
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_ECM \
		NATRON_QT6
CMAKE_OFF=	NATRON_BUILD_TESTS \
		NATRON_SYSTEM_LIBS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/libs/OpenFX/HostSupport/src/ofxhPluginCache.cpp \
		${WRKSRC}/Engine/Settings.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/Engine/AppManager.cpp \
		${WRKSRC}/Engine/Settings.cpp

.include <bsd.port.mk>

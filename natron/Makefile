# $FreeBSD$


PORTNAME=	natron
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.16-beta1
CATEGORIES=	graphics

MAINTAINER=	maintainer@sysctl.cz
COMMENT=	Video compositing software

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>5.14.0:devel/pyside2@${PY_FLAVOR}
RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/IO.ofx.bundle/Contents/Info.plist:graphics/openfx-io \
		${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
		${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena

LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libboost_system.so:devel/boost-libs \
		libshiboken2.cpython-37m.so:devel/shiboken2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libavformat.so:multimedia/ffmpeg \
		libpyside2.cpython-37m.so:devel/pyside2 \
		libfreetype.so:print/freetype \
		libclang.so.11git:devel/llvm-devel

USES=		pkgconfig python:3.7+ qmake qt:5 compiler:c++17-lang shebangfix desktop-file-utils shared-mime-info \
		gettext-runtime desktop-file-utils

USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
GH_TUPLE=	NatronGitHub:openfx:a85dc34:openfx/libs/OpenFX \
		NatronGitHub:google-test:50d6fc3:google_test/Tests/google-test \
		NatronGitHub:google-mock:17945db:google_mock/Tests/google-mock \
		NatronGitHub:google-breakpad:9474c3f:google_breakpad/libs/google-breakpad \
		NatronGitHub:SequenceParsing:9e8b77a:SequenceParsing/libs/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/libs/SequenceParsing/tinydir \
		NatronGitHub:OpenColorIO-Configs:557b981:OpenColorIO_Configs/OpenColorIO-Configs

USE_QT=		core gui qmake_build buildtools_build network opengl
USE_XORG=	x11 pixman
USE_GL=		gl

SHEBANG_FILES=	OpenColorIO-Configs/nuke-default/make.py

BINARY_ALIAS=	python3-config=python${PYTHON_VER}-config

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/OFX/Plugins|${PREFIX}/OFX/Plugins|g' \
		${WRKSRC}/libs/OpenFX/Examples/Makefile.master \
		${WRKSRC}/libs/OpenFX/Support/Plugins/Makefile.master \
		${WRKSRC}/libs/OpenFX/HostSupport/src/ofxhPluginCache.cpp \
		${WRKSRC}/Engine/Settings.cpp
	@${REINPLACE_CMD} -e 's|/usr/share/|${PREFIX}/share/|g' \
		${WRKSRC}/Engine/AppManager.cpp \
		${WRKSRC}/Engine/Settings.cpp \
		${WRKSRC}/Natron.spec

.include <bsd.port.mk>

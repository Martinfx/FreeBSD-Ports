PORTNAME=	natron
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0-alpha.2
CATEGORIES=	graphics

MAINTAINER=	maintainer@sysctl.cz
COMMENT=	compositing software Video

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside2>5.14.0:devel/pyside2@${PY_FLAVOR}

RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/IO.ofx.bundle/Contents/Info.plist:graphics/openfx-io \
#		${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
#		${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2 \
		libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}

USES=		compiler:c++17-lang desktop-file-utils gettext-runtime \
		pkgconfig python:3.8 qmake qt:5 shared-mime-info shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
GH_TUPLE=	NatronGitHub:google-breakpad:9474c3f:google_breakpad/libs/google-breakpad \
		NatronGitHub:google-mock:17945db:google_mock/Tests/google-mock \
		NatronGitHub:google-test:50d6fc3:google_test/Tests/google-test \
		NatronGitHub:OpenColorIO-Configs:557b981:OpenColorIO_Configs/OpenColorIO-Configs \
		NatronGitHub:openfx:a85dc34:openfx/libs/OpenFX \
		NatronGitHub:SequenceParsing:9e8b77a:SequenceParsing/libs/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/libs/SequenceParsing/tinydir

USE_QT=		concurrent core gui network opengl widgets buildtools_build \
		qmake_build
USE_XORG=	pixman x11
USE_GL=		gl

QMAKE_ARGS+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} PYTHON_LIB=${PYTHON_LIB} \
		PYTHON_LIBDIR=${PYTHON_LIBDIR} \
		PYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		PYTHON_SHIBOKEN2_INCLUDE="${PYTHONBASE}/include/shiboken2" \
		PYTHON_VER=${PYTHON_VER}

SHEBANG_FILES=		OpenColorIO-Configs/nuke-default/make.py
BINARY_ALIAS=		python-config=python${PYTHON_VER}-config \
			python=python${PYTHON_VER}
PYTHON_MAKE_ARGS=	PYTHON=0

#MAKE_ENV+=	C_INCLUDE_PATH=${LOCALBASE}/include \
#		CPLUS_INCLUDE_PATH=${LOCALBASE}/include

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

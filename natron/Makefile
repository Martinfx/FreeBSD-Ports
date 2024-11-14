PORTNAME=	natron
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.1-pre2
CATEGORIES=	graphics

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	compositing software Video
WWW=		http://www.natron.fr

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyside6>6.7.3:devel/pyside2@${PY_FLAVOR}

RUN_DEPENDS=	${LOCALBASE}/OFX/Plugins/Shadertoy.ofx.bundle/Contents/Info.plist:graphics/openfx-misc \
		${LOCALBASE}/OFX/Plugins/Arena.ofx.bundle/Contents/Info.plist:graphics/openfx-arena

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libcairo.so:graphics/cairo \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpyside2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/pyside2 \
		libshiboken2.cpython-${PYTHON_SUFFIX}${PYTHON_ABIVER}.so:devel/shiboken2@${PY_FLAVOR}

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		gsed:textproc/gsed

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-runtime \
		pkgconfig python:3.11 qt:6 shared-mime-info shebangfix
USE_XORG+=	sm ice x11 xext

USE_GITHUB=	yes
GH_ACCOUNT=	NatronGitHub
GH_PROJECT=	Natron
GH_TUPLE=	NatronGitHub:google-breakpad:9474c3f7f9939391f281d46c42bfe20cc0f0abd9:google_breakpad/libs/google-breakpad \
		NatronGitHub:google-mock:17945db42c0b42496b2f3c6530307979f2e2a5ce:google_mock/Tests/google-mock \
		NatronGitHub:google-test:50d6fc317c843a2e40dbf08c2efd3f068801ae6d:google_test/Tests/google-test \
		NatronGitHub:OpenColorIO-Configs:557b981:OpenColorIO_Configs/OpenColorIO-Configs \
		NatronGitHub:openfx:0759758d0fb57932b5c4698fff9ef6b4a3132309:openfx/libs/OpenFX \
		NatronGitHub:SequenceParsing:3c93fcc488632b0bdfeee3181586809932357598:SequenceParsing/libs/SequenceParsing \
		NatronGitHub:tinydir:3aae922:tinydir/libs/SequenceParsing/tinydir

USE_QT=		base
USE_XORG=	pixman x11
USE_GL=		gl

QMAKE_ARGS+=	PYTHON_INCLUDEDIR=${PYTHON_INCLUDEDIR} PYTHON_LIB=${PYTHON_LIB} \
		PYTHON_LIBDIR=${PYTHON_LIBDIR} \
		PYTHON_PACKAGES_PATH="${PYTHON_SITELIBDIR}" \
		PYTHON_SHIBOKEN2_INCLUDE="${PYTHONBASE}/include/shiboken2" \
		PYTHON_VER=${PYTHON_VER}

SHEBANG_FILES=		OpenColorIO-Configs/nuke-default/make.py
BINARY_ALIAS=		python-config=python${PYTHON_VER}-config \
			python=python${PYTHON_VER} \
			sed=gsed
PYTHON_MAKE_ARGS=	PYTHON=0

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
PORTNAME=	sourcetrail
DISTVERSION=	2025.9.9
CATEGORIES=	devel java

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Sourcetrail - free and open-source interactive source explorer.
WWW=		https://github.com/petermost/Sourcetrail

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	bash:shells/bash \
		boost-libs>0:devel/boost-libs \
		java:java/openjdk21 \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT} \
		maven>0:devel/maven \
		sqlite3>0:databases/sqlite3 \
		tinyxml>0:textproc/tinyxml

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libboost_charconv.so:devel/boost-libs \
		libboost_chrono.so:devel/boost-libs \
		libboost_date_time.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_locale.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs \
		libicudata.so:devel/icu \
		libicui18n.so:devel/icu \
		libicuuc.so:devel/icu \
		libtinyxml.so:textproc/tinyxml

USES=		cmake java:build llvm:19,build pkgconfig qt:6 sqlite
USE_QT=		base svg
USE_GL=		gl opengl
USE_GITHUB=	yes
GH_ACCOUNT=	petermost
GH_PROJECT=	Sourcetrail

CMAKE_ON=	BUILD_CXX_LANGUAGE_PACKAGE
CMAKE_OFF=	BUILD_JAVA_LANGUAGE_PACKAGE BUILD_PYTHON_LANGUAGE_PACKAGE \
		BUILD_UNIT_TESTS_PACKAGE

CMAKE_ARGS=	-DClang_DIR=${LLVM_PREFIX}/lib/cmake/clang \
		-DCMAKE_PREFIX_PATH=${LLVM_PREFIX} \
		-DLLVM_DIR=/${LLVM_PREFIX}/lib/cmake/llvm
post-patch:
	@${REINPLACE_CMD} -e 's|\$${WRKDIR}|${WRKDIR}|g' \
		${WRKSRC}/java_indexer/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/app/Sourcetrail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/app/sourcetrail_indexer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${BUILD_WRKSRC}/app/data ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

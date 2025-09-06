PORTNAME=	pyside6-qtads
DISTVERSION=	4.4.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyside6_qtads-${DISTVERSION}

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	PySide6 bindings to Qt Advanced Docking System
WWW=		https://github.com/mborgerson/pyside6_qtads

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}shiboken6>0:devel/shiboken6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR}

RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils flavors
#CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
#		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
#		-DADS_BUILD_DEMO=OFF \
#		-DBUILD_EXAMPLES=OFF \
#		-DQT_VERSION_MAJOR=6

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

.include <bsd.port.mk>


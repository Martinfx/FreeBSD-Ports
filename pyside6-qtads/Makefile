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
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6-tools>0:devel/pyside6-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cmake-build-extension>0:devel/pycmake-build-extension@${PY_FLAVOR}


RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR}

NO_ARCH=	yes
USES=		cmake ninja python
USE_PYTHON=	autoplist distutils flavors
CONFIGURE_ENV+=	CMAKE_GENERATOR="Unix Makefiles"
#CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
#		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
#		-DADS_BUILD_DEMO=OFF \
#		-DBUILD_EXAMPLES=OFF \
#		-DQT_VERSION_MAJOR=6

#do-build:
#	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

.include <bsd.port.mk>


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

USES=		cmake python qt:6
USE_PYTHON=	autoplist flavors pep517
USE_QT=		base 

.include <bsd.port.mk>


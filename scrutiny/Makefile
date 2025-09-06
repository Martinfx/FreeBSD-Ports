PORTNAME=	scrutiny-main
DISTVERSIONPREFIX=v
DISTVERSION=	0.8.0
CATEGORIES=	sysutils python

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Scrutiny Debugger Python framework
WWW=		https://scrutinydebugger.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=40.9.0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	nuitka:devel/nuitka \
		${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylink-square>=0:devel/py-pylink-square@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/py-pyside6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imageio>0:graphics/py-imageio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	scrutinydebugger
GH_PROJECT=	scrutiny-main


.include <bsd.port.mk>

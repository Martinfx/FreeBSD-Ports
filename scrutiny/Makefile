PORTNAME=	scrutiny-main
DISTVERSIONPREFIX=v
DISTVERSION=	0.8.0
CATEGORIES=	sysutils python

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	 Small CLI utility that does X
WWW=		 https://scrutinydebugger.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>0:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylink-square>=0:comms/py-pylink-square@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	scrutinydebugger
GH_PROJECT=	scrutiny-main

.include <bsd.port.mk>

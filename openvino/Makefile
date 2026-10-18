PORTNAME=	openvino
DISTVERSION=	2026.4.1
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	OpenVINO™ is an open source toolkit for optimizing and deploying AI inference
WWW=		https://docs.openvino.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jax>=0.4.2:math/py-jax@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR} \
		opencl>0:devel/opencl \
		patchelf>0:sysutils/patchelf

LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
		libtbb.so:devel/onetbb
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake pkgconfig python

USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	openvinotoolkit
GH_PROJECT=	openvino
GH_TUPLE=	herumi:xbyak:431abd865e70a46d56f5aa0e1f87572decb60169:xbyak_/thirdparty/xbyak \
		madler:zlib:51b7f2a:zlib/thirdparty/zlib/zlib \
		zeux:pugixml:ee86beb:pugixml/thirdparty/pugixml \
		gflags:gflags:e171aa2:gflags/thirdparty/gflags/gflags \
		openvinotoolkit:googletest:03e2ed1:gtest/thirdparty/gtest/gtest \
		KhronosGroup:OpenCL-ICD-Loader:b7bd280:icd/thirdparty/ocl/icd_loader \
		KhronosGroup:OpenCL-Headers:6fe718c:head/thirdparty/ocl/cl_headers \
		KhronosGroup:OpenCL-CLHPP:5661a0e:clhpp/thirdparty/ocl/clhpp_headers \
		onnx:onnx:2bb5046:onnx/thirdparty/onnx/onnx \
		protocolbuffers:protobuf:d651109:protobuf/thirdparty/protobuf/protobuf \
		abseil:abseil-cpp:4a2c633:abseil/thirdparty/protobuf/protobuf/third_party/abseil-cpp \
		pybind:pybind11:45fab40:pybind/src/bindings/python/thirdparty/pybind11 \
		intel:ittapi:ca45fef:ittapy/thirdparty/ittapi/ittapi \
		nithinn:ncc:63e59ed:ncc/cmake/developer_package/ncc_naming_style/ncc \
		oneapi-src:level-zero:46cf801:zero/thirdparty/level_zero/level-zero \
		nlohmann:json:9cca280:json/thirdparty/json/nlohmann_json \
		google:flatbuffers:595bf00:flatbuffers/thirdparty/flatbuffers/flatbuffers \
		google:snappy:2c94e11:snapppy/thirdparty/snappy \
		intel:level-zero-npu-extensions:b11dc98:npu/src/plugins/intel_npu/thirdparty/level-zero-ext \
		jbeder:yaml-cpp:da82fd9:yaml/src/plugins/intel_npu/thirdparty/yaml-cpp \
		openvinotoolkit:telemetry:8abddc3:telemetry/thirdparty/telemetry \
		libxsmm:libxsmm:13df674:libxsmm/src/plugins/intel_cpu/thirdparty/libxsmm \
		openvinotoolkit:oneDNN:1289c3b:onednn_/src/plugins/intel_cpu/thirdparty/onednn \
		ARM-software:kleidiai:dc50c2e:kleidiai/src/plugins/intel_cpu/thirdparty/kleidiai \
		herumi:xbyak_riscv:07139a6:xbyak/src/plugins/intel_cpu/thirdparty/xbyak_riscv \
		openvinotoolkit:mlas:d1bc25e:mlas/src/plugins/intel_cpu/thirdparty/mlas \
		oneapi-src:oneDNN:a3d4597:onednn/src/plugins/intel_gpu/thirdparty/onednn_gpu

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		-DDNNL_GPU_RUNTIME:STRING=OCL \
		-DONEDNN_ENABLE_PRIMITIVE:STRING=ALL \
		-DTBB_DIR="${LOCALBASE}/lib/cmake/TBB/"
# use the bundled copies even when the system ones are installed: the
# system ONNX pulls in the system protobuf on top of the bundled one, the
# others would only make the build depend on what happens to be installed
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_ittapi:BOOL=ON \
		-DCMAKE_DISABLE_FIND_PACKAGE_nlohmann_json:BOOL=ON \
		-DCMAKE_DISABLE_FIND_PACKAGE_ONNX:BOOL=ON \
		-DCMAKE_DISABLE_FIND_PACKAGE_OpenCV:BOOL=ON \
		-DCMAKE_DISABLE_FIND_PACKAGE_xbyak:BOOL=ON

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_OV_IR_FRONTEND ENABLE_OV_JAX_FRONTEND \
		ENABLE_OV_ONNX_FRONTEND ENABLE_OV_PADDLE_FRONTEND \
		ENABLE_OV_PYTORCH_FRONTEND ENABLE_OV_TF_LITE_FRONTEND \
		ENABLE_ONEDNN_FOR_GPU ENABLE_PKGCONFIG_GEN ENABLE_PLUGINS_XML \
		ENABLE_PYTHON ENABLE_SAMPLES ENABLE_SYSTEM_OPENCL \
		ENABLE_SYSTEM_TBB ENABLE_INTEL_NPU ENABLE_INTEL_NPU_COMPILER
# TBBBind comes with devel/onetbb, the prebuilt static one is for Linux only
CMAKE_OFF=	ENABLE_JS ENABLE_SYSTEM_FLATBUFFERS ENABLE_TBBBIND_2_5 \
		ONEDNN_BUILD_GRAPH # broken NPU API

.include <bsd.port.pre.mk>

# ComputeLibrary is used by the CPU plugin on ARM only
.if ${ARCH} == aarch64 || ${ARCH} == armv7
BUILD_DEPENDS+=	computelibrary>0:devel/computelibrary
CMAKE_ARGS+=	-DARM_COMPUTE_INCLUDE_DIR=${LOCALBASE}/include/computelibrary \
		-DARM_COMPUTE_LIB_DIR=${LOCALBASE}/lib
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/setupvars.sh
	${RM} -rf ${STAGEDIR}${PREFIX}/install_dependencies
	${RM} -rf ${STAGEDIR}${PREFIX}/licenses

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/src/bindings/python/src/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/bindings/c/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/core/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}/frontend
	cd ${WRKSRC}/src/frontends/common/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/ir/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/gguf/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/onnx/frontend/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/pytorch/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/tensorflow/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/frontends/tensorflow_lite/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/src/inference/include/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_LIB} ${WRKSRC}/bin/intel64/Release/libopenvino*  ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/bin/intel64/Release/benchmark_app ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/bin/intel64/Release/python/${PORTNAME} && \
		for f in $$(${FIND} . -name '*.so'); do \
			${INSTALL_LIB} $${f} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/$${f}; \
		done

.include <bsd.port.post.mk>

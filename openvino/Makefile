PORTNAME=	openvino
DISTVERSION=	2026.1.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	OpenVINO™ is an open source toolkit for optimizing and deploying AI inference
WWW=		https://docs.openvino.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		computelibrary>0:devel/computelibrary

LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libOpenCL.so:devel/ocl-icd

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	openvinotoolkit
GH_PROJECT=	openvino
GH_TUPLE=	herumi:xbyak:0d67fd1530016b7c56f3cd74b3fca920f4c3e2b4:xbyak_/thirdparty/xbyak \
		madler:zlib:51b7f2a:zlib/thirdparty/zlib/zlib \
		zeux:pugixml:ee86beb:pugixml/thirdparty/pugixml \
		gflags:gflags:e171aa2:gflags/thirdparty/gflags/gflags \
		openvinotoolkit:googletest:99760ac:gtest/thirdparty/gtest/gtest \
		KhronosGroup:OpenCL-ICD-Loader:5907ac1:icd/thirdparty/ocl/icd_loader \
		KhronosGroup:OpenCL-Headers:4ea6df1:head/thirdparty/ocl/cl_headers \
		KhronosGroup:OpenCL-CLHPP:c7b4ade:clhpp/thirdparty/ocl/clhpp_headers \
		onnx:onnx:e709452:onnx/thirdparty/onnx/onnx \
		protocolbuffers:protobuf:f0dc78d:protobuf/thirdparty/protobuf/protobuf \
		pybind:pybind11:f5fbe86:pybind/src/bindings/python/thirdparty/pybind11 \
		intel:ittapi:ca45fef:ittapy/thirdparty/ittapi/ittapi \
		nithinn:ncc:63e59ed:ncc/cmake/developer_package/ncc_naming_style/ncc \
		oneapi-src:level-zero:d562046:zero/thirdparty/level_zero/level-zero \
		nlohmann:json:9cca280:json/thirdparty/json/nlohmann_json \
		google:flatbuffers:595bf00:flatbuffers/thirdparty/flatbuffers/flatbuffers \
		google:snappy:2c94e11:snapppy/thirdparty/snappy \
		intel:level-zero-npu-extensions:42768cc:npu/src/plugins/intel_npu/thirdparty/level-zero-ext \
		jbeder:yaml-cpp:da82fd9:yaml/src/plugins/intel_npu/thirdparty/yaml-cpp \
		openvinotoolkit:telemetry:8abddc3:telemetry/thirdparty/telemetry \
		libxsmm:libxsmm:13df674:libxsmm/src/plugins/intel_cpu/thirdparty/libxsmm \
		openvinotoolkit:oneDNN:6b6492b:onednn_/src/plugins/intel_cpu/thirdparty/onednn \
		ARM-software:kleidiai:7d82645:kleidiai/src/plugins/intel_cpu/thirdparty/kleidiai \
		herumi:xbyak_riscv:07139a6:xbyak/src/plugins/intel_cpu/thirdparty/xbyak_riscv \
		openvinotoolkit:mlas:d1bc25e:mlas/src/plugins/intel_cpu/thirdparty/mlas \
		oneapi-src:oneDNN:470e87e:onednn/src/plugins/intel_gpu/thirdparty/onednn_gpu

CMAKE_ARGS=	-DARM_COMPUTE_INCLUDE_DIR=${LOCALBASE}/include/computelibrary \
		-DARM_COMPUTE_LIB_DIR=${LOCALBASE}/lib \
		-DDNNL_GPU_RUNTIME:STRING=OCL \
		-DONEDNN_ENABLE_PRIMITIVE:STRING=ALL \
		-DTBB_DIR="${LOCALBASE}/lib/cmake/TBB/"

CMAKE_ON=	BUILD_SHARED_LIBS ENABLE_SYSTEM_TBB ENABLE_SAMPLES
CMAKE_OFF=	ENABLE_INTEL_NPU ENABLE_INTEL_NPU_COMPILER \
		ENABLE_ONEDNN_FOR_GPU ONEDNN_BUILD_GRAPH ENABLE_JS # broken NPU API

post-install:
	${RM} ${STAGEDIR}${PREFIX}/setupvars.sh
	${RM} -rf ${STAGEDIR}${PREFIX}/install_dependencies
	${RM} -rf ${STAGEDIR}${PREFIX}/licenses

.include <bsd.port.mk>
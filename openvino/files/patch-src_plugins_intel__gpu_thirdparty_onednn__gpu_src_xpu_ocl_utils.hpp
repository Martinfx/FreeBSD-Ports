--- src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/ocl/utils.hpp.orig	2026-04-10 07:28:54 UTC
+++ src/plugins/intel_gpu/thirdparty/onednn_gpu/src/xpu/ocl/utils.hpp
@@ -78,7 +78,7 @@ const char *convert_cl_int_to_str(cl_int
 
 #if defined(_WIN32)
 #define OCL_LIB_NAME "OpenCL.dll"
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define OCL_LIB_NAME "libOpenCL.so.1"
 #endif
 

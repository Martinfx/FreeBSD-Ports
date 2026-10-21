--- src/plugins/intel_gpu/src/runtime/ocl/ocl_engine.cpp.orig	2026-10-17 12:30:00 UTC
+++ src/plugins/intel_gpu/src/runtime/ocl/ocl_engine.cpp
@@ -118,7 +118,7 @@
                     "[GPU] Selected OpenCL device does not advertise cl_khr_external_memory; "
                     "external memory import is not supported");
 
-#ifndef CL_VERSION_3_0
+#if !defined(CL_VERSION_3_0) || !(defined(_WIN32) || defined(__linux__))
     OPENVINO_THROW("[GPU] External memory import is not supported on this platform");
 #else
 #ifdef _WIN32

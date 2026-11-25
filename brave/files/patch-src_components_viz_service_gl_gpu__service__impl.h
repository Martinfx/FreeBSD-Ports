--- src/components/viz/service/gl/gpu_service_impl.h.orig	2026-11-24 12:50:30 UTC
+++ src/components/viz/service/gl/gpu_service_impl.h
@@ -459,7 +459,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 

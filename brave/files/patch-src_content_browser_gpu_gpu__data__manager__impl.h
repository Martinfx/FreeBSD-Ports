--- src/content/browser/gpu/gpu_data_manager_impl.h.orig	2026-11-24 12:50:30 UTC
+++ src/content/browser/gpu/gpu_data_manager_impl.h
@@ -224,7 +224,7 @@ class CONTENT_EXPORT GpuDataManagerImpl
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 

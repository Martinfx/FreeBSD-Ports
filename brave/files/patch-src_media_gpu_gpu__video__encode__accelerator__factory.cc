--- src/media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2026-11-24 12:50:30 UTC
+++ src/media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -71,7 +71,7 @@ std::unique_ptr<VideoEncodeAccelerator>
 
 #if BUILDFLAG(USE_VAAPI)
 std::unique_ptr<VideoEncodeAccelerator> CreateVaapiVEA() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     return nullptr;
   }

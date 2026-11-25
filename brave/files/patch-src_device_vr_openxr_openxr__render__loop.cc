--- src/device/vr/openxr/openxr_render_loop.cc.orig	2026-11-24 12:50:30 UTC
+++ src/device/vr/openxr/openxr_render_loop.cc
@@ -1047,7 +1047,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 
   // No GPU fence: a CPU finish guarantees the WebGL write completed before the
   // binding reads the shared image. WaitOnFence is a no-op without a fence FD.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The finish is only needed if the flushed write left no fence to wait on.
   gpu::ClientSharedImage::WaitSyncTokenAndSignal(
       std::move(shared_images), std::move(combined_sync_tokens), gl,
@@ -1065,7 +1065,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenXrRenderLoop::OnWebXrWritesFlushed(
     int16_t frame_index,
     std::vector<LayerId> updated_layers) {

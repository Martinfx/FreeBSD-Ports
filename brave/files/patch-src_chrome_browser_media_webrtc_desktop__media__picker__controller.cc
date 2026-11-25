--- src/chrome/browser/media/webrtc/desktop_media_picker_controller.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/media/webrtc/desktop_media_picker_controller.cc
@@ -115,7 +115,7 @@ bool DesktopMediaPickerController::IsSys
   } else {
     return media::IsMacCatapSystemLoopbackCaptureSupported();
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (request_source == Params::RequestSource::kCast) {
     return base::FeatureList::IsEnabled(media::kPulseaudioLoopbackForCast);
   } else {

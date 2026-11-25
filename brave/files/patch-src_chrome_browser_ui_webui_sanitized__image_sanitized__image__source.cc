--- src/chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc
@@ -352,7 +352,7 @@ void SanitizedImageSource::OnAnimationDe
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_frames.size() > 1) {
     // The image is animated, re-encode as WebP animated image and send to
     // requester.

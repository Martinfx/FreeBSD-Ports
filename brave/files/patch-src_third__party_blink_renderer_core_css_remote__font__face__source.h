--- src/third_party/blink/renderer/core/css/remote_font_face_source.h.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/blink/renderer/core/css/remote_font_face_source.h
@@ -7,6 +7,7 @@
 
 #include "base/task/single_thread_task_runner.h"
 #include "base/time/time.h"
+#include "build/build_config.h"
 #include "third_party/blink/renderer/core/css/css_font_face_source.h"
 #include "third_party/blink/renderer/core/execution_context/security_context.h"
 #include "third_party/blink/renderer/core/loader/resource/font_resource.h"
@@ -159,7 +160,10 @@ class RemoteFontFaceSource final : publi
   // |nullptr| if font is not loaded or failed to decode.
   Member<const FontCustomPlatformData> custom_font_data_;
   // |nullptr| if font is not an IFT font.
+#if !BUILDFLAG(IS_BSD)
+  // XXX crubit
   Member<IftCustomFontData> ift_custom_font_data_;
+#endif
   // |nullptr| if font is not loaded or failed to decode.
   String url_;
 

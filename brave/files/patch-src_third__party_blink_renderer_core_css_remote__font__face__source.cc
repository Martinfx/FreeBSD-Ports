--- src/third_party/blink/renderer/core/css/remote_font_face_source.cc.orig	2026-11-02 23:22:33 UTC
+++ src/third_party/blink/renderer/core/css/remote_font_face_source.cc
@@ -14,7 +14,9 @@
 #include "third_party/blink/renderer/core/css/css_custom_font_data.h"
 #include "third_party/blink/renderer/core/css/css_font_face.h"
 #include "third_party/blink/renderer/core/css/font_face_set_document.h"
+#if !BUILDFLAG(IS_BSD)
 #include "third_party/blink/renderer/core/css/ift_custom_font_data.h"
+#endif
 #include "third_party/blink/renderer/core/dom/document.h"
 #include "third_party/blink/renderer/core/frame/local_dom_window.h"
 #include "third_party/blink/renderer/core/frame/local_frame.h"
@@ -219,9 +221,12 @@ void RemoteFontFaceSource::NotifyFinishe
   DCHECK(!custom_font_data_);
   if (resource->PassedIntegrityChecks() || !check_integrity) {
     custom_font_data_ = font->GetCustomFontData();
+#if !BUILDFLAG(IS_BSD)
+    // XXX crubit
     if (RuntimeEnabledFeatures::IncrementalFontTransferEnabled()) {
       ift_custom_font_data_ = IftCustomFontData::MaybeCreate(this, *font);
     }
+#endif
   }
   url_ = resource->Url().GetString();
 
@@ -349,9 +354,13 @@ const SimpleFontData* RemoteFontFaceSour
 
   histograms_.RecordFallbackTime();
 
+#if BUILDFLAG(IS_BSD)
+  CustomFontData* custom_font_data = MakeGarbageCollected<CustomFontData>();
+#else
   CustomFontData* custom_font_data =
       ift_custom_font_data_ ? ift_custom_font_data_.Get()
                             : MakeGarbageCollected<CustomFontData>();
+#endif
   return MakeGarbageCollected<SimpleFontData>(
       custom_font_data_->GetFontPlatformData(
           font_description.EffectiveFontSize(),
@@ -451,7 +460,9 @@ void RemoteFontFaceSource::Trace(Visitor
   visitor->Trace(face_);
   visitor->Trace(font_selector_);
   visitor->Trace(custom_font_data_);
+#if !BUILDFLAG(IS_BSD)
   visitor->Trace(ift_custom_font_data_);
+#endif
   CSSFontFaceSource::Trace(visitor);
   FontResourceClient::Trace(visitor);
 }

--- src/third_party/blink/renderer/core/xml/xslt_processor.h.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/blink/renderer/core/xml/xslt_processor.h
@@ -91,7 +91,11 @@ class XSLTProcessor final : public Scrip
 
   void reset();
 
+#if (LIBXML_VERSION >= 21200)
   static void ParseErrorFunc(void* user_data, const xmlError*);
+#else
+  static void ParseErrorFunc(void* user_data, xmlError*);
+#endif
   static void GenericErrorFunc(void* user_data, const char* msg, ...);
 
   // Only for libXSLT callbacks

--- core/Common/3dParty/libxml/libxml2/error.c.orig	2026-04-27 00:00:00 UTC
+++ core/Common/3dParty/libxml/libxml2/error.c
@@ -228,6 +228,7 @@
  * @param msg  printf-like format string
  * @param ...  arguments to format
  */
+#ifndef XML_ERROR_DISABLE_MODE
 void
 xmlGenericErrorDefaultFunc(void *ctx ATTRIBUTE_UNUSED, const char *msg, ...) {
     va_list args;
@@ -239,6 +240,12 @@
     vfprintf((FILE *)xmlGenericErrorContext, msg, args);
     va_end(args);
 }
+#else
+void
+xmlGenericErrorDefaultFunc(void *ctx ATTRIBUTE_UNUSED, const char *msg, ...) {
+	// NONE
+}
+#endif
 
 /**
  * Set the thread-local "generic" handler and context for error

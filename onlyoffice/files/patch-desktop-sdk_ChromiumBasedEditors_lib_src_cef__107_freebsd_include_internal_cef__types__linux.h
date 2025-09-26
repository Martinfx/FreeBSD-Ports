--- desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/include/internal/cef_types_linux.h.orig	2025-09-26 18:27:35 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef_107/freebsd/include/internal/cef_types_linux.h
@@ -34,7 +34,7 @@
 #include "include/base/cef_build.h"
 #include "include/cef_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_FREEBSD)
 
 #if defined(CEF_X11)
 typedef union _XEvent XEvent;

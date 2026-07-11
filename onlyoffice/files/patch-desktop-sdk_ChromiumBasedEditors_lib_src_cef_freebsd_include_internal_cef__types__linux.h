--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/include/internal/cef_types_linux.h.orig	2025-09-24 18:11:29 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/include/internal/cef_types_linux.h
@@ -34,7 +34,7 @@
 #include "include/base/cef_build.h"
 #include "include/cef_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(CEF_X11)
 typedef union _XEvent XEvent;
@@ -47,7 +47,7 @@ typedef struct _XDisplay XDisplay;
 
 // Handle types.
 #if defined(CEF_X11)
-#define cef_cursor_handle_t unsigned long
+#define cef_cursor_handle_t int
 #define cef_event_handle_t XEvent*
 #else
 #define cef_cursor_handle_t void*

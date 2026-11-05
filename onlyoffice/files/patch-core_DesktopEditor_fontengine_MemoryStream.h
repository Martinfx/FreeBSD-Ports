--- core/DesktopEditor/fontengine/MemoryStream.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/fontengine/MemoryStream.h
@@ -44,7 +44,7 @@
 // #define _LOGGING_NATIVE_
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <stdlib.h>
 #endif
 

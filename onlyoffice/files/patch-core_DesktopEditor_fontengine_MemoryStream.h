--- core/DesktopEditor/fontengine/MemoryStream.h.orig	2025-09-24 06:04:09 UTC
+++ core/DesktopEditor/fontengine/MemoryStream.h
@@ -41,7 +41,7 @@
 // #define _LOGGING_NATIVE_
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <stdlib.h>
 #endif
 

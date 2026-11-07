--- core/DesktopEditor/cximage/tiff/tiffconf.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/tiff/tiffconf.h
@@ -33,7 +33,7 @@
 #define TIFF_UINT64_T unsigned __int64
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <inttypes.h>
 
 /* Signed 64-bit type */

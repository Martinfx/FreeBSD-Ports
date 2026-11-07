--- core/DesktopEditor/cximage/CxImage/ximapng.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/CxImage/ximapng.h
@@ -22,7 +22,7 @@
 #if CXIMAGE_SUPPORT_PNG
 
 extern "C" {
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #undef _DLL
  #include <png.h>
  #include <pngstruct.h>

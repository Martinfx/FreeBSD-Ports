--- core/DesktopEditor/cximage/CxImage/ximajpg.h.orig	2025-09-24 05:48:36 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajpg.h
@@ -29,7 +29,7 @@ extern "C" {
 #define CXIMAGEJPG_SUPPORT_EXIF CXIMAGE_SUPPORT_EXIF
 
 extern "C" {
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jpeglib.h>
  #include <jerror.h>
 #else

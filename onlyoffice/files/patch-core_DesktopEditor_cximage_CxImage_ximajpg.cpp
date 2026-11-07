--- core/DesktopEditor/cximage/CxImage/ximajpg.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajpg.cpp
@@ -10,7 +10,7 @@
 
 #if CXIMAGE_SUPPORT_JPG
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jmorecfg.h>
 #else
  #include "../jpeg/jmorecfg.h"

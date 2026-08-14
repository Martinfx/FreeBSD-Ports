--- core/DesktopEditor/cximage/CxImage/ximajpg.cpp.orig	2025-09-24 05:47:46 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajpg.cpp
@@ -9,7 +9,7 @@
 
 #if CXIMAGE_SUPPORT_JPG
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jmorecfg.h>
 #else
  #include "../jpeg/jmorecfg.h"

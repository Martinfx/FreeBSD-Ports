--- core/DesktopEditor/cximage/CxImage/ximajas.h.orig	2025-09-24 05:42:35 UTC
+++ core/DesktopEditor/cximage/CxImage/ximajas.h
@@ -16,7 +16,7 @@
 
 #if CXIMAGE_SUPPORT_JASPER
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
  #include <jasper/jasper.h>
 #else
  #include "../jasper/include/jasper/jasper.h"

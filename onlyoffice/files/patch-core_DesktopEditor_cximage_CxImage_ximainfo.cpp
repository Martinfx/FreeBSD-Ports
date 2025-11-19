--- core/DesktopEditor/cximage/CxImage/ximainfo.cpp.orig	2025-09-24 05:35:49 UTC
+++ core/DesktopEditor/cximage/CxImage/ximainfo.cpp
@@ -5,7 +5,7 @@
 
 #include "ximage.h"
 
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__FreeBSD__)
     #ifdef UNICODE
         #define _tcsnicmp(a,b,c) wcscasecmp(a,b)
     #else

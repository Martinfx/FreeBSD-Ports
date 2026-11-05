--- core/DesktopEditor/cximage/CxImage/ximage.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/cximage/CxImage/ximage.h
@@ -52,7 +52,7 @@
 #pragma once
 #endif 
 
-#ifdef _LINUX
+#if  defined(_LINUX) || defined(__FreeBSD__)
   #define _XOPEN_SOURCE
   #include <unistd.h>
   #include <arpa/inet.h>

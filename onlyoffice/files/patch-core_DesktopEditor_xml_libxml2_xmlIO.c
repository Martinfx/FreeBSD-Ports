--- core/DesktopEditor/xml/libxml2/xmlIO.c.orig	2025-09-24 06:22:37 UTC
+++ core/DesktopEditor/xml/libxml2/xmlIO.c
@@ -43,7 +43,7 @@
 #include <windows.h>
 #include "io.h"
 #endif
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "unistd.h"
 #endif
 

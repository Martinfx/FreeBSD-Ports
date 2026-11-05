--- core/DesktopEditor/fontengine/fontconverter/MemoryUtils.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/fontengine/fontconverter/MemoryUtils.h
@@ -40,7 +40,7 @@
 #include <string>
 #include <stdlib.h>
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
     #include <string.h>
 #endif
 

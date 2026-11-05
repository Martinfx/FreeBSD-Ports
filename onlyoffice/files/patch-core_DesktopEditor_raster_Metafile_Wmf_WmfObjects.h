--- core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h
@@ -40,7 +40,7 @@
 
 #include "WmfTypes.h"
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
     #include <string.h> //memset oO
 #endif
 namespace MetaFile

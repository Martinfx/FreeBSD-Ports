--- core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h.orig	2025-09-24 06:14:55 UTC
+++ core/DesktopEditor/raster/Metafile/Wmf/WmfObjects.h
@@ -37,7 +37,7 @@
 
 #include "WmfTypes.h"
 
-#ifdef __linux__
+#ifdef __linux__ || __FreeBSD__
     #include <string.h> //memset oO
 #endif
 namespace MetaFile

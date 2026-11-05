--- core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h
@@ -997,7 +997,7 @@
 			}
 			else
 			{
-				pRegion->shScanCount = NULL;
+				pRegion->shScanCount = 0;
 			}
 
 

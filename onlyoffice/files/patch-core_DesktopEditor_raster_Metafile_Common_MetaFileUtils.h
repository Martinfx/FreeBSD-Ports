--- core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h.orig	2025-09-24 06:10:02 UTC
+++ core/DesktopEditor/raster/Metafile/Common/MetaFileUtils.h
@@ -994,7 +994,7 @@ namespace MetaFile
 			}
 			else
 			{
-				pRegion->shScanCount = NULL;
+				pRegion->shScanCount = 0;
 			}
 
 

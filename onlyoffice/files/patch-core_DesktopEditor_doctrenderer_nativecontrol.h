--- core/DesktopEditor/doctrenderer/nativecontrol.h.orig	2025-09-24 11:22:26 UTC
+++ core/DesktopEditor/doctrenderer/nativecontrol.h
@@ -327,7 +327,7 @@ namespace NSNativeControl
 
 				if (m_map_access_directories.end() == m_map_access_directories.find(NSFile::GetDirectoryName(strFile)))
 				{
-					*pData = NULL;
+					pData = NULL;
 					dwLen = 0;
 					return;
 				}

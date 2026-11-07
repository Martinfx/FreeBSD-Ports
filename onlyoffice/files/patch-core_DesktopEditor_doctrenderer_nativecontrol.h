--- core/DesktopEditor/doctrenderer/nativecontrol.h.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/doctrenderer/nativecontrol.h
@@ -330,7 +330,7 @@
 
 				if (m_map_access_directories.end() == m_map_access_directories.find(NSFile::GetDirectoryName(strFile)))
 				{
-					*pData = NULL;
+					pData = NULL;
 					dwLen = 0;
 					return;
 				}

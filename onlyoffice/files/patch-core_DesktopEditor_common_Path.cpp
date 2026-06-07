--- core/DesktopEditor/common/Path.cpp.orig	2025-09-23 23:00:51 UTC
+++ core/DesktopEditor/common/Path.cpp
@@ -35,7 +35,7 @@
 
 #if defined(_WIN32) || defined (_WIN64)
 #include <tchar.h>
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 #include <libgen.h>
 #endif
 
@@ -54,7 +54,7 @@ namespace NSSystemPath
 		sRes.append(tFolder);
 		if(sRes.length() > 0)
 			sRes.erase(sRes.length()-1);
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strFileName.c_str(), strFileName.length(), pUtf8, lLen, false);
@@ -74,7 +74,7 @@ namespace NSSystemPath
 		sRes.append(tFilename);
 		sRes.append(tExt);
 		return sRes;
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strFileName.c_str(), strFileName.length(), pUtf8, lLen, false);

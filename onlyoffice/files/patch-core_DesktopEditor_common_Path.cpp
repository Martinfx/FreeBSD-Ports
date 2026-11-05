--- core/DesktopEditor/common/Path.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/common/Path.cpp
@@ -39,7 +39,7 @@
 
 #if defined(_WIN32) || defined (_WIN64)
 #include <tchar.h>
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 #include <libgen.h>
 #endif
 
@@ -58,7 +58,7 @@
 		sRes.append(tFolder);
 		if(sRes.length() > 0)
 			sRes.erase(sRes.length()-1);
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strFileName.c_str(), strFileName.length(), pUtf8, lLen, false);
@@ -78,7 +78,7 @@
 		sRes.append(tFilename);
 		sRes.append(tExt);
 		return sRes;
-#elif __linux__ || MAC
+#elif __linux__ || __FreeBSD__ || MAC
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strFileName.c_str(), strFileName.length(), pUtf8, lLen, false);

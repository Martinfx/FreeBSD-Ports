--- core/DesktopEditor/common/Directory.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/common/Directory.cpp
@@ -38,7 +38,7 @@
 #include "windef.h"
 #include <shlobj.h>
 #include <Rpc.h>
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -127,7 +127,7 @@
 		FindClose( hRes );
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -242,7 +242,7 @@
 			}
 		} while( FindNextFileW( hRes, &oFD ) );
 		FindClose( hRes );
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -306,7 +306,7 @@
 #if defined(_WIN32) || defined (_WIN64)
 		DWORD dwAttrib = ::GetFileAttributesW(strDirectory.c_str());
 		return (dwAttrib != INVALID_FILE_ATTRIBUTES && 0 != (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);
@@ -405,7 +405,7 @@
 		return true;
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strSrc.c_str(), strSrc.length(), pUtf8, lLen, false);
@@ -553,7 +553,7 @@
 #endif
 #if defined(_WIN32) || defined (_WIN64)
 		if (deleteRoot) RemoveDirectoryW(strDirectory.c_str());
-#elif __linux__
+#elif defined(__linux__) || defined(__FreeBSD__)
 		BYTE* pUtf8 = NULL;
 		LONG lLen = 0;
 		NSFile::CUtf8Converter::GetUtf8StringFromUnicode(strDirectory.c_str(), strDirectory.length(), pUtf8, lLen, false);

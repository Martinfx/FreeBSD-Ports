--- core/HtmlFile/HtmlFile.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/HtmlFile/HtmlFile.cpp
@@ -48,7 +48,7 @@
 #include <vector>
 #include <map>
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -475,7 +475,7 @@
     NSFile::CFileBinary::Remove(sTempFileForParams);
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
     std::wstring sTempFileForParams = NSFile::CFileBinary::CreateTempFileWithUniqueName(NSFile::CFileBinary::GetTempPath(), L"XML");
     NSFile::CFileBinary oFile;
     oFile.CreateFileW(sTempFileForParams);

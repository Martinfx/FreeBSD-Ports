--- core/HtmlFile/HtmlFile.cpp.orig	2025-09-24 09:30:24 UTC
+++ core/HtmlFile/HtmlFile.cpp
@@ -45,7 +45,7 @@
 #include <vector>
 #include <map>
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <sys/wait.h>
 #include <stdio.h>
@@ -472,7 +472,7 @@ int CHtmlFile::Convert(const std::vector<std::wstring>
     NSFile::CFileBinary::Remove(sTempFileForParams);
 #endif
 
-#ifdef LINUX
+#if defined(LINUX) || defined(__FreeBSD__)
     std::wstring sTempFileForParams = NSFile::CFileBinary::CreateTempFileWithUniqueName(NSFile::CFileBinary::GetTempPath(), L"XML");
     NSFile::CFileBinary oFile;
     oFile.CreateFileW(sTempFileForParams);

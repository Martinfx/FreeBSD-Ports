--- core/DesktopEditor/common/File.cpp.orig	2025-09-23 23:00:51 UTC
+++ core/DesktopEditor/common/File.cpp
@@ -39,10 +39,14 @@
 #include <windows.h>
 #endif
 
-#ifdef _LINUX
+#if defined(_LINUX) || defined(__FreeBSD__)
 #include <unistd.h>
 #include <string.h>
 #include <sys/stat.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include <sys/time.h>
 #include <utime.h>
 #endif
@@ -1924,6 +1928,23 @@ namespace NSFile
 #endif
 			return L"";
 		}
+
+		std::string sUTF8(buf);
+		std::wstring sRet = CUtf8Converter::GetUnicodeStringFromUTF8((BYTE*)sUTF8.c_str(), sUTF8.length());
+		return sRet;
+#endif
+
+#if defined(__FreeBSD__)
+                int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+                char buf[NS_FILE_MAX_PATH];
+                size_t size = NS_FILE_MAX_PATH;
+        
+                memset(buf, 0, NS_FILE_MAX_PATH);
+                if (sysctl(mib, 4, &buf, &size, NULL, 0) != 0) {
+                    size = readlink("/proc/curproc/file", buf, size - 1);
+                    if (size < 0)
+                    return L"";
+                }
 
 		std::string sUTF8(buf);
 		std::wstring sRet = CUtf8Converter::GetUnicodeStringFromUTF8((BYTE*)sUTF8.c_str(), sUTF8.length());

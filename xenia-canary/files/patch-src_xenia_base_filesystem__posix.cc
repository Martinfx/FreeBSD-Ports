--- src/xenia/base/filesystem_posix.cc.orig
+++ src/xenia/base/filesystem_posix.cc
@@ -28,6 +28,9 @@
 #include <limits.h>
 #include <mach-o/dyld.h>
 #endif
+#if XE_PLATFORM_FREEBSD
+#include <sys/sysctl.h>
+#endif
 
 namespace xe {
 
@@ -59,6 +62,15 @@ std::filesystem::path GetExecutablePath() {
     return std::string(path);
   }
   return std::string();
+#elif XE_PLATFORM_FREEBSD
+  // procfs is usually not mounted on FreeBSD.
+  char path[PATH_MAX];
+  size_t size = sizeof(path);
+  const int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+  if (sysctl(mib, 4, path, &size, nullptr, 0) == 0) {
+    return std::string(path);
+  }
+  return std::string();
 #else
   char buff[FILENAME_MAX] = "";
   ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff) - 1);

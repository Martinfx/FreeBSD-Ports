--- src/Util.cpp.orig	2019-10-19 03:13:32 UTC
+++ src/Util.cpp
@@ -20,6 +20,12 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined( __NetBSD__) || defined(__DragonFly__)
+#define CAN_GET_RUNNING_PROGRAM_NAME
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/syslimits.h> // For PATH_MAX
+#endif
 #ifdef __linux__
 #define CAN_GET_RUNNING_PROGRAM_NAME
 #include <linux/limits.h>  // For PATH_MAX
@@ -77,11 +83,24 @@ string running_program_name() {
 #else
     string program_name;
     char path[PATH_MAX] = {0};
-    uint32_t size = sizeof(path);
 #if defined(__linux__)
+    size_t size = sizeof(path);
     ssize_t len = ::readlink("/proc/self/exe", path, size - 1);
 #elif defined(__APPLE__)
+    size_t size = sizeof(path);
     ssize_t len = ::_NSGetExecutablePath(path, &size);
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+    int mib[4];
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PATHNAME;
+    mib[3] = -1;
+
+    size_t len = sizeof(path);
+    if (sysctl(mib, 4, path, &len, NULL, 0) != 0) {
+        path[0] = '\0';
+    }
+
 #endif
     if (len != -1) {
 #if defined(__linux__)

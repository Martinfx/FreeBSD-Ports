--- src/fsutils.cpp.orig	2026-03-07 00:00:00 UTC
+++ src/fsutils.cpp
@@ -8,6 +8,13 @@
 #include <cstring>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <cerrno>
+#include <climits>
+#endif
+
 #include <spdlog/spdlog.h>
 
 #include "logger_manager.h"
@@ -40,6 +47,19 @@
     std::filesystem::path execpath(filepath.data());
     return execpath.parent_path();
 }
+#elif defined(__FreeBSD__)
+static std::filesystem::path get_executable_directory() {
+    int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
+    char filepath[PATH_MAX];
+    size_t size = sizeof(filepath);
+
+    if (sysctl(mib, 4, filepath, &size, nullptr, 0) != 0) {
+        logger()->error("Error getting executable path: {}", std::strerror(errno));
+        return std::filesystem::path();
+    }
+
+    return std::filesystem::path(filepath).parent_path();
+}
 #else   // _WIN32
 static std::filesystem::path get_executable_directory() {
     std::error_code ec;
@@ -83,8 +103,8 @@
         );
     }
 
-    // 3. The Linux standard local data directory
-    candidates.push_back(std::filesystem::path("/usr/local/share/video2x") / resource);
+    // 3. The port's data directory
+    candidates.push_back(std::filesystem::path("%%DATADIR%%") / resource);
 
     // 4. The Linux standard data directory
     candidates.push_back(std::filesystem::path("/usr/share/video2x") / resource);

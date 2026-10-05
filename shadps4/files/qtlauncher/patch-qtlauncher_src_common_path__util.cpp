--- qtlauncher/src/common/path_util.cpp.orig	2026-10-02 19:05:42 UTC
+++ qtlauncher/src/common/path_util.cpp
@@ -98,7 +98,7 @@
 #ifdef __APPLE__
         user_dir =
             std::filesystem::path(getenv("HOME")) / "Library" / "Application Support" / "shadPS4";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         const char* xdg_data_home = getenv("XDG_DATA_HOME");
         if (xdg_data_home != nullptr && strlen(xdg_data_home) > 0) {
             user_dir = std::filesystem::path(xdg_data_home) / "shadPS4";
@@ -120,7 +120,7 @@
 #ifdef __APPLE__
         launcher_dir = std::filesystem::path(getenv("HOME")) / "Library" / "Application Support" /
                        "shadPS4QtLauncher";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         const char* xdg_data_home = getenv("XDG_DATA_HOME");
         if (xdg_data_home != nullptr && strlen(xdg_data_home) > 0) {
             launcher_dir = std::filesystem::path(xdg_data_home) / "shadPS4QtLauncher";

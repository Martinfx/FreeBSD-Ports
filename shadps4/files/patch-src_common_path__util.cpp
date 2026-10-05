--- src/common/path_util.cpp.orig	2026-10-02 12:00:00 UTC
+++ src/common/path_util.cpp
@@ -94,7 +94,7 @@
 #ifdef __APPLE__
         user_dir =
             std::filesystem::path(getenv("HOME")) / "Library" / "Application Support" / "shadPS4";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         const char* xdg_data_home = getenv("XDG_DATA_HOME");
         if (xdg_data_home != nullptr && strlen(xdg_data_home) > 0) {
             user_dir = std::filesystem::path(xdg_data_home) / "shadPS4";
@@ -111,7 +111,8 @@
     std::unordered_map<PathType, fs::path> paths;
 
     const auto create_path = [&](PathType shad_path, const fs::path& new_path) {
-        std::filesystem::create_directory(new_path);
+        // The XDG parent (~/.local/share) does not necessarily exist yet.
+        std::filesystem::create_directories(new_path);
         paths.insert_or_assign(shad_path, new_path);
     };
 

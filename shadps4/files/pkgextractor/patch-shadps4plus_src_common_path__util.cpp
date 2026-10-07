--- shadps4plus/src/common/path_util.cpp.orig	2026-01-22 18:54:16 UTC
+++ shadps4plus/src/common/path_util.cpp
@@ -104,7 +104,7 @@
 #ifdef __APPLE__
         user_dir =
             std::filesystem::path(getenv("HOME")) / "Library" / "Application Support" / "shadPS4";
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
         const char* xdg_data_home = getenv("XDG_DATA_HOME");
         if (xdg_data_home != nullptr && strlen(xdg_data_home) > 0) {
             user_dir = std::filesystem::path(xdg_data_home) / "shadPS4";
@@ -121,7 +121,7 @@
     std::unordered_map<PathType, fs::path> paths;
 
     const auto create_path = [&](PathType shad_path, const fs::path& new_path) {
-        std::filesystem::create_directory(new_path);
+        std::filesystem::create_directories(new_path);
         paths.insert_or_assign(shad_path, new_path);
     };
 

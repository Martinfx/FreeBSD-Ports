--- vita3k/app/src/app_init.cpp.orig	2026-10-06 04:21:17 UTC
+++ vita3k/app/src/app_init.cpp
@@ -190,7 +190,7 @@ void init_paths(Root &root_paths) {
         root_paths.set_cache_path(base_path / "cache" / "");
         root_paths.set_patch_path(base_path / "patch" / "");
 
-#if defined(__linux__) && !defined(__ANDROID__) && !defined(__APPLE__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__) && !defined(__APPLE__)
         // XDG Data Dirs.
         auto env_home = getenv("HOME");
         auto XDG_DATA_DIRS = getenv("XDG_DATA_DIRS");
@@ -218,6 +218,8 @@ void init_paths(Root &root_paths) {
         // Don't assume that base_path is portable.
         if (fs::exists(root_paths.get_base_path() / "data") && fs::exists(root_paths.get_base_path() / "lang") && fs::exists(root_paths.get_base_path() / "shaders-builtin"))
             root_paths.set_static_assets_path(root_paths.get_base_path());
+        else if (fs::exists(fs::path("%%DATADIR%%") / "data") && fs::exists(fs::path("%%DATADIR%%") / "lang") && fs::exists(fs::path("%%DATADIR%%") / "shaders-builtin"))
+            root_paths.set_static_assets_path(fs::path("%%DATADIR%%") / "");
         else if (env_home != NULL)
             root_paths.set_static_assets_path(fs::path(env_home) / ".local/share" / app_name / "");
 
@@ -282,7 +284,7 @@ bool init(EmuEnvState &state, Config &cf
     }
 
     LOG_INFO("Base path: {}", state.base_path);
-#if defined(__linux__) && !defined(__ANDROID__) && !defined(__APPLE__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && !defined(__ANDROID__) && !defined(__APPLE__)
     LOG_INFO("Static assets path: {}", state.static_assets_path);
     LOG_INFO("Shared path: {}", state.shared_path);
     LOG_INFO("Log path: {}", state.log_path);

--- src/plugins/intel_gpu/src/plugin/custom_layer.cpp.orig	2026-04-10 09:34:51 UTC
+++ src/plugins/intel_gpu/src/plugin/custom_layer.cpp
@@ -245,7 +245,7 @@ void CustomLayer::LoadFromFile(const std
 #ifdef _WIN32
     char path[MAX_PATH];
     char* abs_path_ptr = _fullpath(path, configFile.c_str(), MAX_PATH);
-#elif __linux__
+#elif __FreeBSD__
     char path[PATH_MAX];
     char* abs_path_ptr = realpath(configFile.c_str(), path);
 #else

--- src/main.cpp.orig	2025-07-28 10:20:16 UTC
+++ src/main.cpp
@@ -18,6 +18,7 @@
 #include <chrono>
 #include <thread>
 #include <filesystem>
+#include <icicle.h>
 GLFWwindow* window = nullptr;
 #if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
 #pragma comment(lib, "legacy_stdio_definitions")

--- src/video_core/renderer_vulkan/vk_platform.cpp.orig	2025-08-27 21:30:18 UTC
+++ src/video_core/renderer_vulkan/vk_platform.cpp
@@ -8,7 +8,7 @@
 #define VK_USE_PLATFORM_WIN32_KHR
 #elif defined(__APPLE__)
 #define VK_USE_PLATFORM_METAL_EXT
-#else
+#elif defined(__FreeBSD__)
 #define VK_USE_PLATFORM_WAYLAND_KHR
 #define VK_USE_PLATFORM_XLIB_KHR
 #endif

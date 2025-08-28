--- src/video_core/renderer_vulkan/vk_instance.h.orig	2025-08-28 03:30:42 UTC
+++ src/video_core/renderer_vulkan/vk_instance.h
@@ -9,7 +9,7 @@
 #include "video_core/renderer_vulkan/vk_platform.h"
 
 #define TRACY_VK_USE_SYMBOL_TABLE
-#include <tracy/TracyVulkan.hpp>
+#include <tracy/tracy/TracyVulkan.hpp>
 
 namespace Frontend {
 class WindowSDL;

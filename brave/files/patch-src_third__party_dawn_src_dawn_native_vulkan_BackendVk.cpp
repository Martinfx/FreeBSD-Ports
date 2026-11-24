--- src/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -58,7 +58,7 @@ constexpr char kSwiftshaderLibName[] = "
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";

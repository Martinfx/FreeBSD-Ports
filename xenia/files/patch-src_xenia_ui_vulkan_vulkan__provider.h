--- src/xenia/ui/vulkan/vulkan_provider.h.orig	2024-05-25 13:31:50 UTC
+++ src/xenia/ui/vulkan/vulkan_provider.h
@@ -26,7 +26,7 @@
 #ifndef VK_USE_PLATFORM_ANDROID_KHR
 #define VK_USE_PLATFORM_ANDROID_KHR 1
 #endif
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX || XE_PLATFORM_FREEBSD
 #ifndef VK_USE_PLATFORM_XCB_KHR
 #define VK_USE_PLATFORM_XCB_KHR 1
 #endif
@@ -247,7 +247,7 @@ class VulkanProvider : public GraphicsProvider {
     bool khr_surface;
 #if XE_PLATFORM_ANDROID
     bool khr_android_surface;
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX || XE_PLATFORM_FREEBSD
     bool khr_xcb_surface;
 #elif XE_PLATFORM_WIN32
     bool khr_win32_surface;
@@ -267,7 +267,7 @@ class VulkanProvider : public GraphicsProvider {
 #include "xenia/ui/vulkan/functions/instance_khr_surface.inc"
 #if XE_PLATFORM_ANDROID
 #include "xenia/ui/vulkan/functions/instance_khr_android_surface.inc"
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX || XE_PLATFORM_FREEBSD
 #include "xenia/ui/vulkan/functions/instance_khr_xcb_surface.inc"
 #elif XE_PLATFORM_WIN32
 #include "xenia/ui/vulkan/functions/instance_khr_win32_surface.inc"
@@ -394,7 +394,7 @@ class VulkanProvider : public GraphicsProvider {
 
   RenderdocApi renderdoc_api_;
 
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   void* library_ = nullptr;
 #elif XE_PLATFORM_WIN32
   HMODULE library_ = nullptr;

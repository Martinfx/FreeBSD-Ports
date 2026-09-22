--- src/xenia/ui/vulkan/vulkan_provider.cc.orig	2025-03-06 14:31:26 UTC
+++ src/xenia/ui/vulkan/vulkan_provider.cc
@@ -24,7 +24,7 @@
 #include "xenia/ui/vulkan/vulkan_immediate_drawer.h"
 #include "xenia/ui/vulkan/vulkan_presenter.h"
 
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
 #include <dlfcn.h>
 #elif XE_PLATFORM_WIN32
 #include "xenia/base/platform_win.h"
@@ -94,7 +94,7 @@ VulkanProvider::~VulkanProvider() {
     lfn_.vkDestroyInstance(instance_, nullptr);
   }
 
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   if (library_) {
     dlclose(library_);
   }
@@ -110,7 +110,7 @@ bool VulkanProvider::Initialize() {
 
   // Load the library.
   bool library_functions_loaded = true;
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
 #if XE_PLATFORM_ANDROID
   const char* libvulkan_name = "libvulkan.so";
 #else
@@ -403,7 +403,7 @@ bool VulkanProvider::Initialize() {
 #include "xenia/ui/vulkan/functions/instance_khr_android_surface.inc"
     instance_extensions_.khr_android_surface = functions_loaded;
   }
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX  || XE_PLATFORM_FREEBSD
   if (instance_extensions_.khr_xcb_surface) {
     bool functions_loaded = true;
 #include "xenia/ui/vulkan/functions/instance_khr_xcb_surface.inc"
@@ -449,7 +449,7 @@ bool VulkanProvider::Initialize() {
 #if XE_PLATFORM_ANDROID
   XELOGVK("  * VK_KHR_android_surface: {}",
           instance_extensions_.khr_android_surface ? "yes" : "no");
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX  || XE_PLATFORM_FREEBSD
   XELOGVK("  * VK_KHR_xcb_surface: {}",
           instance_extensions_.khr_xcb_surface ? "yes" : "no");
 #elif XE_PLATFORM_WIN32
@@ -641,7 +641,7 @@ void VulkanProvider::AccumulateInstanceExtensions(
         instance_extensions_enabled.push_back("VK_KHR_android_surface");
         instance_extensions.khr_android_surface = true;
       }
-#elif XE_PLATFORM_GNU_LINUX
+#elif XE_PLATFORM_GNU_LINUX  || XE_PLATFORM_FREEBSD
       if (!instance_extensions.khr_xcb_surface &&
           !std::strcmp(instance_extension_name, "VK_KHR_xcb_surface")) {
         instance_extensions_enabled.push_back("VK_KHR_xcb_surface");

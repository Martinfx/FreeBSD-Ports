--- src/vulkanview.cpp.orig	2024-11-27 09:27:36 UTC
+++ src/vulkanview.cpp
@@ -43,7 +43,7 @@ VulkanView::VulkanView(ViewerStatusBar* statusBar, QWi
     mInstance.setExtensions(Renderer::instanceExtensions);
 
     // Set up Dynamic Dispatch Loader to use with vulkan.hpp
-    vk::DynamicLoader dl;
+    vk::detail::DynamicLoader dl;
     PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr =
         dl.getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
     VULKAN_HPP_DEFAULT_DISPATCHER.init(vkGetInstanceProcAddr);

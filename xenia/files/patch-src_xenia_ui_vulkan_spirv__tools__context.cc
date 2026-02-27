--- src/xenia/ui/vulkan/spirv_tools_context.cc.orig	2025-03-06 14:27:32 UTC
+++ src/xenia/ui/vulkan/spirv_tools_context.cc
@@ -34,7 +34,7 @@ bool SpirvToolsContext::Initialize(unsigned int spirv_
     return false;
   }
   std::filesystem::path vulkan_sdk_path(vulkan_sdk_env);
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX || XE_PLATFORM_FREEBSD
   library_ = dlopen((vulkan_sdk_path / "bin/libSPIRV-Tools-shared.so").c_str(),
                     RTLD_NOW | RTLD_LOCAL);
   if (!library_) {

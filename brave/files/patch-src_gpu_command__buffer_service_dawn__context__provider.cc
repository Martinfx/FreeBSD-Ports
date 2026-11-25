--- src/gpu/command_buffer/service/dawn_context_provider.cc.orig	2026-11-24 12:50:30 UTC
+++ src/gpu/command_buffer/service/dawn_context_provider.cc
@@ -504,7 +504,7 @@ wgpu::BackendType DawnContextProvider::G
   }
 #if BUILDFLAG(IS_WIN)
   return wgpu::BackendType::D3D11;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return wgpu::BackendType::Vulkan;
 #elif BUILDFLAG(IS_APPLE)
   return wgpu::BackendType::Metal;

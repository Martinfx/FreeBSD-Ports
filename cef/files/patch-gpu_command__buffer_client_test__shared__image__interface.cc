--- gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-11-11 22:13:17 UTC
+++ gpu/command_buffer/client/test_shared_image_interface.cc
@@ -28,8 +28,10 @@
 #include "ui/gfx/gpu_fence.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
 #include <linux/memfd.h>
+#endif
 #include <sys/mman.h>
 #include <unistd.h>
 #endif
@@ -437,7 +439,7 @@ TestSharedImageInterface::CreateSharedIm
   return image;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<ClientSharedImage>
 TestSharedImageInterface::CreateNativePixmapBackedSharedImage(
     const SharedImageInfo& si_info,

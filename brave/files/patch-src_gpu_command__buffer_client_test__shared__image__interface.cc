--- src/gpu/command_buffer/client/test_shared_image_interface.cc.orig	2026-11-24 12:50:30 UTC
+++ src/gpu/command_buffer/client/test_shared_image_interface.cc
@@ -29,7 +29,7 @@
 #include "ui/gfx/gpu_fence.h"
 #include "ui/gfx/gpu_memory_buffer_handle.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <linux/memfd.h>
 #include <sys/mman.h>
 #include <unistd.h>
@@ -434,7 +434,7 @@ TestSharedImageInterface::CreateSharedIm
   return image;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 scoped_refptr<ClientSharedImage>
 TestSharedImageInterface::CreateNativePixmapBackedSharedImage(
     const SharedImageInfo& si_info,

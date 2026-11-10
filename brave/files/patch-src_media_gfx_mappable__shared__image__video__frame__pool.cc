--- src/media/gfx/mappable_shared_image_video_frame_pool.cc.orig	2026-11-02 23:22:33 UTC
+++ src/media/gfx/mappable_shared_image_video_frame_pool.cc
@@ -674,7 +674,7 @@ void MappableSharedImageVideoFramePool::
   }
 
   bool is_software_backed_video_frame = !video_frame->HasSharedImage();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 

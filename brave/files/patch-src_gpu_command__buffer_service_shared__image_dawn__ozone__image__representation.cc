--- src/gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc.orig	2026-11-24 12:50:30 UTC
+++ src/gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc
@@ -199,6 +199,7 @@ void DawnOzoneImageRepresentation::EndAc
   if (!texture_) {
     return;
   }
+#if 0
   wgpu::SharedTextureMemoryEndAccessState end_access_desc = {};
   wgpu::SharedTextureMemoryVkImageLayoutEndState end_layout{};
   end_access_desc.nextInChain = &end_layout;
@@ -249,6 +250,12 @@ void DawnOzoneImageRepresentation::EndAc
 
   texture_.Destroy();
   texture_ = nullptr;
+#else
+    LOG(ERROR) << "Failed to end access for DawnOzoneImageRepresentation";
+    texture_.Destroy();
+    texture_ = nullptr;
+    return;
+#endif
 }
 
 }  // namespace gpu

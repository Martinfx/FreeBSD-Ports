--- gfx/webrender_bindings/webrender_ffi.h.orig	2022-12-01 10:31:04 UTC
+++ gfx/webrender_bindings/webrender_ffi.h
@@ -73,8 +73,6 @@ struct WrPipelineInfo;
 struct WrPipelineIdAndEpoch;
 using WrPipelineIdEpochs = nsTArray<WrPipelineIdAndEpoch>;
 
-const uint64_t ROOT_CLIP_CHAIN = ~0;
-
 }  // namespace wr
 }  // namespace mozilla
 

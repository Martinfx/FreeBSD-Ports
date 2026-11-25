--- src/device/vr/openxr/openxr_graphics_binding.cc.orig	2026-11-24 12:50:30 UTC
+++ src/device/vr/openxr/openxr_graphics_binding.cc
@@ -309,7 +309,7 @@ bool OpenXrGraphicsBinding::WaitOnBaseLa
   return WaitOnFence(*base_layer_, gpu_fence);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenXrGraphicsBinding::WaitOnImplicitFences(
     const std::vector<LayerId>& updated_layers) {
   if (layers_sequence_.empty()) {
@@ -565,7 +565,7 @@ bool OpenXrGraphicsBinding::CreateCompos
   if (!SupportsLayers()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The page's layer of an unsupported type never becomes active.
   if (!SupportsLayerType(OpenXrCompositionLayer::GetTypeFromMojomData(
           *layer_data->mutable_data->layer_data))) {

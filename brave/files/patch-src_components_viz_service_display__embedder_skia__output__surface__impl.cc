--- src/components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1456,7 +1456,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::G
                                         VK_IMAGE_TILING_OPTIMAL, vk_format,
                                         si_format, image_context->color_space(),
                                         image_context->ycbcr_info());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,

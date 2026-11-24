--- src/gpu/ipc/client/client_shared_image_interface.cc.orig	2026-11-24 12:50:30 UTC
+++ src/gpu/ipc/client/client_shared_image_interface.cc
@@ -168,7 +168,7 @@ scoped_refptr<ClientSharedImage> ClientS
   CHECK(!si_info.format.PrefersExternalSampler()) << si_info.format.ToString();
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Only valid client from renderer on ChromeOS and Linux is VideoCapture, that
   // uses SCANOUT_VEA_CPU_READ.
   if (gpu_channel_->client_type() == viz::mojom::GpuClientType::kRenderer) {

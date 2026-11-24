--- src/gpu/ipc/client/shared_image_interface_proxy.cc.orig	2026-11-24 12:50:30 UTC
+++ src/gpu/ipc/client/shared_image_interface_proxy.cc
@@ -261,7 +261,7 @@ Mailbox SharedImageInterfaceProxy::Creat
   // TODO(kylechar): Verify buffer_handle works for size+format.
   auto mailbox = Mailbox::Generate();
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (host_->client_type() == viz::mojom::GpuClientType::kRenderer) {
     // Only valid client from renderer on ChromeOS and Linux is VideoCapture,
     // that supposed to produce linear buffers.

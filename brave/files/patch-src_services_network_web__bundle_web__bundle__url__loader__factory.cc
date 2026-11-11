--- src/services/network/web_bundle/web_bundle_url_loader_factory.cc.orig	2026-11-02 23:22:33 UTC
+++ src/services/network/web_bundle/web_bundle_url_loader_factory.cc
@@ -577,6 +577,7 @@ bool WebBundleURLLoaderFactory::HasError
 
 void WebBundleURLLoaderFactory::SetBundleStream(
     mojo::ScopedDataPipeConsumerHandle body) {
+#if !BUILDFLAG(IS_BSD)
   if (HasError())
     return;
   mojo::PendingRemote<web_package::mojom::BundleDataSource> data_source;
@@ -596,6 +597,11 @@ void WebBundleURLLoaderFactory::SetBundl
       /*offset=*/std::nullopt,
       base::BindOnce(&WebBundleURLLoaderFactory::OnMetadataParsed,
                      weak_ptr_factory_.GetWeakPtr()));
+#else
+  // XXX crubit
+  NOTIMPLEMENTED();
+  return;
+#endif
 }
 
 mojo::PendingRemote<mojom::URLLoaderClient>

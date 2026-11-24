--- src/net/url_request/url_request_context_builder.cc.orig	2026-11-24 12:50:30 UTC
+++ src/net/url_request/url_request_context_builder.cc
@@ -454,7 +454,7 @@ std::unique_ptr<URLRequestContext> URLRe
   }
 
   if (!proxy_resolution_service_) {
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     // TODO(willchan): Switch to using this code when
     // ProxyConfigService::CreateSystemProxyConfigService()'s
     // signature doesn't suck.

--- src/content/public/browser/content_browser_client.cc.orig	2026-11-24 12:50:30 UTC
+++ src/content/public/browser/content_browser_client.cc
@@ -1437,7 +1437,7 @@ bool ContentBrowserClient::ShouldRunOutO
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

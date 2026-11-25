--- src/components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/safe_browsing/core/browser/realtime/url_lookup_service_base.cc
@@ -122,7 +122,7 @@ RTLookupRequest::OSType GetRTLookupReque
   return RTLookupRequest::OS_TYPE_CHROME_OS;
 #elif BUILDFLAG(IS_IOS)
   return RTLookupRequest::OS_TYPE_IOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return RTLookupRequest::OS_TYPE_LINUX;
 #elif BUILDFLAG(IS_MAC)
   return RTLookupRequest::OS_TYPE_MAC;

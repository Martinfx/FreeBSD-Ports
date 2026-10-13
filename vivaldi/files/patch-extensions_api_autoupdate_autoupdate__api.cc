--- extensions/api/autoupdate/autoupdate_api.cc.orig	2026-08-25 00:00:00 UTC
+++ extensions/api/autoupdate/autoupdate_api.cc
@@ -118,7 +118,7 @@ void UpdateEventRouter::DispatchEvent(Pr
 
 AutoUpdateAPI::AutoUpdateAPI(content::BrowserContext* context)
     : browser_context_(context) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   InitUpgradeDetection();
 #endif
 #if !BUILDFLAG(IS_ANDROID)
@@ -132,7 +132,7 @@ AutoUpdateAPI::AutoUpdateAPI(content::Br
 AutoUpdateAPI::~AutoUpdateAPI() {}
 
 void AutoUpdateAPI::Shutdown() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ShutdownUpgradeDetection();
 #endif
 }
@@ -143,7 +143,7 @@ Profile* UpdateAsyncFunction::GetProfile
 
 /* static */
 void AutoUpdateAPI::HandleRestartPreconditions() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   HandleCodecRestartPreconditions();
 #endif  // BUILDFLAG(IS_LINUX)
 }
@@ -296,7 +296,7 @@ void AutoUpdateAPI::HandleWidevineUpdate
 }
 
 void AutoUpdateAPI::HandleRequestedWidevineUpdate() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Note: This handles Restart to reload on linux. For other platforms, we
   // reload the tab in DRMContentTabHelper
   if (widevine_was_available_ || !widevine_was_updated_ ||

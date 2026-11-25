--- src/chrome/browser/after_startup_task_utils.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/after_startup_task_utils.cc
@@ -126,7 +126,7 @@ void SetBrowserStartupIsComplete(Startup
   GetStartupCompleteFlag().Set();
   base::UmaHistogramEnumeration("Startup.BrowserStartupCompleteReason", reason);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Process::Current().CreationTime() is not available on all platforms.
   const base::Time process_creation_time =
       base::Process::Current().CreationTime();

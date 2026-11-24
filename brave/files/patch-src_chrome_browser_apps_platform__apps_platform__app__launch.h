--- src/chrome/browser/apps/platform_apps/platform_app_launch.h.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/apps/platform_apps/platform_app_launch.h
@@ -38,7 +38,7 @@ bool OpenExtensionApplicationWindow(Prof
 content::WebContents* OpenExtensionApplicationTab(Profile* profile,
                                                   const std::string& app_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Opens the deprecated Chrome Apps flow if |app_id| refers to a Chrome App and
 // Chrome Apps are deprecated on the |profile|. Returns true if that was the
 // case, or false otherwise.

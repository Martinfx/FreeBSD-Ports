--- chromium/chrome/browser/first_run/first_run.h.orig	2026-08-20 14:42:05 UTC
+++ chromium/chrome/browser/first_run/first_run.h
@@ -75,7 +75,7 @@ struct MasterPrefs {
 #if BUILDFLAG(IS_MAC)
   bool confirm_to_quit;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool eula_required = !vivaldi::IsVivaldiRunning();
 #endif
 };
@@ -147,7 +147,7 @@ ProcessInitialPreferencesResult ProcessI
     std::unique_ptr<installer::InitialPreferences> initial_prefs,
     MasterPrefs* out_prefs);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Shows the EULA dialog if required. Returns true if the EULA is accepted
 // or not required. Returns false if the EULA has not been accepted. If the EULA
 // has not been accepted, the caller should exit promptly.

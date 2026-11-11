--- src/chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -202,7 +202,7 @@ const char* const kPersistentPrefNames[]
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,

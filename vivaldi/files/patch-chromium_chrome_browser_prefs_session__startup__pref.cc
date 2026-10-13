--- chromium/chrome/browser/prefs/session_startup_pref.cc.orig	2026-03-13 06:02:14 UTC
+++ chromium/chrome/browser/prefs/session_startup_pref.cc
@@ -77,7 +77,7 @@ SessionStartupPref::Type SessionStartupP
   if (vivaldi::IsVivaldiRunning()) {
     return SessionStartupPref::LAST;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }

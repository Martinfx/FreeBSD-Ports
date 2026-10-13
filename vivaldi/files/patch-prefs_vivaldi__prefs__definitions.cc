--- prefs/vivaldi_prefs_definitions.cc.orig	2026-08-25 00:00:00 UTC
+++ prefs/vivaldi_prefs_definitions.cc
@@ -35,7 +35,7 @@
 
 // Preference override is available on Linux or in internal desktop builds on
 // any platform for testing convenience.
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     !(defined(OFFICIAL_BUILD) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS))
 #define VIVALDI_PREFERENCE_OVERRIDE_FILE
 #endif

--- src/headless/lib/browser/headless_web_contents_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/headless/lib/browser/headless_web_contents_impl.cc
@@ -75,7 +75,7 @@ BASE_FEATURE(kPrerender2InHeadlessMode,
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 

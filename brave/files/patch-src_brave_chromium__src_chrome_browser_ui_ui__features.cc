--- src/brave/chromium_src/chrome/browser/ui/ui_features.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/chrome/browser/ui/ui_features.cc
@@ -12,7 +12,7 @@
 namespace features {
 
 OVERRIDE_FEATURE_DEFAULT_STATES({{
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     {kFewerUpdateConfirmations, base::FEATURE_DISABLED_BY_DEFAULT},
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)

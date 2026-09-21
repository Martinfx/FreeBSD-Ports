--- src/brave/chromium_src/components/feature_engagement/public/feature_constants.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/feature_engagement/public/feature_constants.cc
@@ -12,14 +12,14 @@
 
 namespace feature_engagement {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 BASE_FEATURE(kIPHBraveShieldsInPageInfoFeature,
              "IPH_BraveShieldsInPageInfo",
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
 OVERRIDE_FEATURE_DEFAULT_STATES({{
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     {kIPHAutofillAccountNameEmailSuggestionFeature,
      base::FEATURE_DISABLED_BY_DEFAULT},
     {kIPHDiscardRingFeature, base::FEATURE_DISABLED_BY_DEFAULT},

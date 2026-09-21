--- src/brave/chromium_src/components/password_manager/core/browser/features/password_features.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/password_manager/core/browser/features/password_features.cc
@@ -11,7 +11,7 @@
 namespace password_manager::features {
 
 OVERRIDE_FEATURE_DEFAULT_STATES({{
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_IOS) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_MAC) || \
     BUILDFLAG(IS_WIN)
     {kSkipUndecryptablePasswords, base::FEATURE_ENABLED_BY_DEFAULT},
 #endif

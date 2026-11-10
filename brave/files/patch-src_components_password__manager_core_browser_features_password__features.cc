--- src/components/password_manager/core/browser/features/password_features.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/password_manager/core/browser/features/password_features.cc
@@ -81,7 +81,7 @@ BASE_FEATURE(kClearUndecryptablePassword
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -199,7 +199,7 @@ BASE_FEATURE(kPreventPasswordManagerOnFe
 // Remove in or after M155.
 BASE_FEATURE(kRecordPasswordReadiness, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
 #if BUILDFLAG(IS_MAC)
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -219,7 +219,7 @@ BASE_FEATURE(kShowTabWithPasswordChangeO
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_OVERRIDDEN_FEATURE(kSkipUndecryptablePasswords,
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   base::FEATURE_ENABLED_BY_DEFAULT
 #else
   base::FEATURE_DISABLED_BY_DEFAULT

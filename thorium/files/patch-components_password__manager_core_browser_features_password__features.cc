--- components/password_manager/core/browser/features/password_features.cc.orig	2024-04-19 13:02:56 UTC
+++ components/password_manager/core/browser/features/password_features.cc
@@ -30,7 +30,7 @@ BASE_FEATURE(kButterOnDesktopFollowup,
 
 BASE_FEATURE(kClearUndecryptablePasswordsOnSync,
              "ClearUndecryptablePasswordsInSync",
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -99,7 +99,7 @@ BASE_FEATURE(kPasswordManualFallbackAvailable,
              "PasswordManualFallbackAvailable",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kRestartToGainAccessToKeychain,
              "RestartToGainAccessToKeychain",
              base::FEATURE_ENABLED_BY_DEFAULT);

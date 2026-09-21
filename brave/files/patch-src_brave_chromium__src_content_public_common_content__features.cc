--- src/brave/chromium_src/content/public/common/content_features.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/content/public/common/content_features.cc
@@ -24,7 +24,7 @@
     {kServiceWorkerAutoPreload, base::FEATURE_DISABLED_BY_DEFAULT},
     {kWebIdentityDigitalCredentials, base::FEATURE_DISABLED_BY_DEFAULT},
     {kWebIdentityDigitalCredentialsCreation, base::FEATURE_DISABLED_BY_DEFAULT},
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     {kPwaNavigationCapturing, base::FEATURE_DISABLED_BY_DEFAULT},
 #endif
     {kWebOTP, base::FEATURE_DISABLED_BY_DEFAULT},

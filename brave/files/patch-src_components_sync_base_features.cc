--- src/components/sync/base/features.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/sync/base/features.cc
@@ -69,7 +69,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignI
 
 bool IsReplaceSyncPromosWithSignInPromosEnabled() {
   if ((true)) return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(kReplaceSyncPromosWithSignInPromos);

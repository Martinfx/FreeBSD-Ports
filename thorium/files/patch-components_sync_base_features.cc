--- components/sync/base/features.cc.orig	2024-04-19 13:02:56 UTC
+++ components/sync/base/features.cc
@@ -126,7 +126,7 @@ BASE_FEATURE(kEnablePreferencesAccountStorage,
 BASE_FEATURE(kSyncPollImmediatelyOnEveryStartup,
              "SyncPollImmediatelyOnEveryStartup2",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT

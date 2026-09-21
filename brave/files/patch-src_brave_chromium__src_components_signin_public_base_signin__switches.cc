--- src/brave/chromium_src/components/signin/public/base/signin_switches.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/components/signin/public/base/signin_switches.cc
@@ -11,7 +11,7 @@
 namespace switches {
 
 OVERRIDE_FEATURE_DEFAULT_STATES({{
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     {kFirstRunDesktopRefresh, base::FEATURE_DISABLED_BY_DEFAULT},
 #endif
     {kSyncEnableBookmarksInTransportMode, base::FEATURE_DISABLED_BY_DEFAULT},

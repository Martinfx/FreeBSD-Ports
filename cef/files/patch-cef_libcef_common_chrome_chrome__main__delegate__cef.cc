--- cef/libcef/common/chrome/chrome_main_delegate_cef.cc.orig	2026-11-19 22:04:44 UTC
+++ cef/libcef/common/chrome/chrome_main_delegate_cef.cc
@@ -151,7 +151,7 @@ ChromeMainDelegateCef::ChromeMainDelegat
       runner_(runner),
       settings_(settings),
       application_(application) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   resource_util::OverrideAssetPath();
 #endif
 }

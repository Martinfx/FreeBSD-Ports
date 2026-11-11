--- src/chrome/browser/themes/theme_helper.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/themes/theme_helper.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/themes/browser_theme_pack.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 

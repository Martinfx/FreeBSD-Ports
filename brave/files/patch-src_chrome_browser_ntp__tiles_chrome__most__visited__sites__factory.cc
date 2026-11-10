--- src/chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -60,7 +60,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

--- src/chrome/browser/ui/tabs/tab_dialog_manager.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/tabs/tab_dialog_manager.cc
@@ -89,7 +89,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

--- src/components/constrained_window/constrained_window_views.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/constrained_window/constrained_window_views.cc
@@ -419,7 +419,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;

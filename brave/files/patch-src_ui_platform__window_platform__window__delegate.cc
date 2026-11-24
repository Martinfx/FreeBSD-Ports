--- src/ui/platform_window/platform_window_delegate.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/platform_window/platform_window_delegate.cc
@@ -58,7 +58,7 @@ gfx::Insets PlatformWindowDelegate::Calc
   return gfx::Insets();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void PlatformWindowDelegate::OnWindowTiledStateChanged(
     WindowTiledEdges new_tiled_edges) {}
 #endif

--- src/chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/window_sizer/window_sizer.cc
@@ -225,7 +225,7 @@ void WindowSizer::GetBrowserWindowBounds
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux has its own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(

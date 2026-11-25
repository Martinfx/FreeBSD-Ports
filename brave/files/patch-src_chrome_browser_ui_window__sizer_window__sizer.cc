--- src/chrome/browser/ui/window_sizer/window_sizer.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/window_sizer/window_sizer.cc
@@ -225,8 +225,9 @@ void WindowSizer::GetBrowserWindowBounds
       browser, window_bounds, show_state);
 }
 
-#if !BUILDFLAG(IS_LINUX)
-// Linux has its own implementation, see WindowSizerLinux.
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
+// Linux (and the BSDs, which build window_sizer_linux.cc as well) has its
+// own implementation, see WindowSizerLinux.
 // static
 void WindowSizer::GetBrowserWindowBoundsAndShowState(
     std::unique_ptr<StateProvider> state_provider,

--- cef/libcef/browser/chrome/views/chrome_browser_widget.cc.orig	2026-11-19 22:04:44 UTC
+++ cef/libcef/browser/chrome/views/chrome_browser_widget.cc
@@ -74,7 +74,7 @@ void ChromeBrowserWidget::Initialized()
 
   // Based on BrowserWidget::InitBrowserWidget.
   // This is the first call that will trigger theme-related client callbacks.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calls ThemeChanged() or OnNativeThemeUpdated().
   SelectNativeTheme();
 #else

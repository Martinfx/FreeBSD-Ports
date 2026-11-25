--- src/chrome/browser/ui/views/frame/browser_view.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/views/frame/browser_view.cc
@@ -2515,7 +2515,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {

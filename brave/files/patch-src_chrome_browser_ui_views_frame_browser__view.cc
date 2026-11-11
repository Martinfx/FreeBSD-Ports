--- src/chrome/browser/ui/views/frame/browser_view.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/ui/views/frame/browser_view.cc
@@ -2474,7 +2474,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {

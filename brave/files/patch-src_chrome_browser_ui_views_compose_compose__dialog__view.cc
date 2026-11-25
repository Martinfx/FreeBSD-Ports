--- src/chrome/browser/ui/views/compose/compose_dialog_view.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/views/compose/compose_dialog_view.cc
@@ -160,7 +160,7 @@ void ComposeDialogView::OnBeforeBubbleWi
     views::Widget::InitParams* params,
     views::Widget* widget) const {
   WebUIBubbleDialogView::OnBeforeBubbleWidgetInit(params, widget);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // In linux, windows may be clipped to their anchors' bounds,
   // resulting in visual errors, unless they use accelerated rendering. See
   // crbug.com/40912626 for details.

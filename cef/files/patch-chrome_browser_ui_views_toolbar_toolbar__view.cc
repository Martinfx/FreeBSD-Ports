--- chrome/browser/ui/views/toolbar/toolbar_view.cc.orig	2026-11-19 22:05:59 UTC
+++ chrome/browser/ui/views/toolbar/toolbar_view.cc
@@ -442,7 +442,7 @@ void ToolbarView::Init() {
   }
 
   std::unique_ptr<MediaToolbarButtonView> media_button;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!features::IsWebUIMediaButtonEnabled() && BUTTON_VISIBLE(kMedia)) {
     media_button = std::make_unique<MediaToolbarButtonView>(
         browser_view_, std::make_unique<MediaToolbarButtonContextualMenu>(

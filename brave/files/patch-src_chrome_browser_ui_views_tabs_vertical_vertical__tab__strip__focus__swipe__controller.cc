--- src/chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.cc
@@ -25,7 +25,7 @@ VerticalTabStripFocusSwipeController::~V
   region_view_->RemovePreTargetHandler(this);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void VerticalTabStripFocusSwipeController::OnMouseEvent(ui::MouseEvent* event) {
   if (!base::FeatureList::IsEnabled(features::kTabGroupsFocusing) ||
       !region_view_ || region_view_->IsDragging() ||

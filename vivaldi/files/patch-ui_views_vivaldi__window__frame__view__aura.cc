--- ui/views/vivaldi_window_frame_view_aura.cc.orig	2026-08-25 00:00:00 UTC
+++ ui/views/vivaldi_window_frame_view_aura.cc
@@ -95,7 +95,7 @@ gfx::Rect VivaldiWindowFrameViewAura::Ge
 gfx::Rect VivaldiWindowFrameViewAura::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   if (views::Widget* widget = window_->GetWidget()) {

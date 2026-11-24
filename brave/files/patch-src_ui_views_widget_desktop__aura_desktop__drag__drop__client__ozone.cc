--- src/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -259,7 +259,7 @@ DragOperation DesktopDragDropClientOzone
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);

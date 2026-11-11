--- src/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc.orig	2026-11-02 23:22:33 UTC
+++ src/ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.cc
@@ -243,7 +243,7 @@ DragOperation DesktopDragDropClientOzone
   return selected_operation_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopDragDropClientOzone::UpdateDragImage(const gfx::ImageSkia& image,
                                                  const gfx::Vector2d& offset) {
   DCHECK(drag_handler_);

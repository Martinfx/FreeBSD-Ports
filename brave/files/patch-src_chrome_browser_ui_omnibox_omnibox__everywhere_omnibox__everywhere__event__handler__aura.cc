--- src/chrome/browser/ui/omnibox/omnibox_everywhere/omnibox_everywhere_event_handler_aura.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/omnibox/omnibox_everywhere/omnibox_everywhere_event_handler_aura.cc
@@ -20,7 +20,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "ui/views/widget/desktop_aura/desktop_drag_drop_client_win.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_drag_drop_client_ozone.h"
 #endif
 
@@ -44,7 +44,7 @@ gfx::Point GetEventScreenPoint(const ui:
 base::ScopedClosureRunner SuppressDataDragsForWindowMove() {
 #if BUILDFLAG(IS_WIN)
   return views::DesktopDragDropClientWin::ScopedSuppressForWindowMove();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return views::DesktopDragDropClientOzone::ScopedSuppressForWindowMove();
 #else
   return base::ScopedClosureRunner();

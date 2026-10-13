--- chromium/ui/views/controls/menu/menu_controller.cc.orig	2026-08-25 00:00:00 UTC
+++ chromium/ui/views/controls/menu/menu_controller.cc
@@ -2119,7 +2119,7 @@ bool MenuController::OnKeyPressed(const
       break;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (vivaldi::IsVivaldiRunning()) {
     // We want Alt to close the Vivaldi menu as under Windows. For consistency
     // we enable it for all menus. VB-39080

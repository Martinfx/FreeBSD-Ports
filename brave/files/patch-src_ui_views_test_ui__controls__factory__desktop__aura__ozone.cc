--- src/ui/views/test/ui_controls_factory_desktop_aura_ozone.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/views/test/ui_controls_factory_desktop_aura_ozone.cc
@@ -241,7 +241,7 @@ bool SendMouseClick(MouseButton type, gf
                          window_hint);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 void ForceUseScreenCoordinatesOnce() {
   g_ozone_ui_controls_test_helper->ForceUseScreenCoordinatesOnce();

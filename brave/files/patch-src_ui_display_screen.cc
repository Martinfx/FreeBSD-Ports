--- src/ui/display/screen.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/display/screen.cc
@@ -82,7 +82,7 @@ void Screen::SetDisplayForNewWindows(int
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {

--- ui/ozone/public/ozone_ui_controls_test_helper.cc.orig	2026-11-11 22:13:17 UTC
+++ ui/ozone/public/ozone_ui_controls_test_helper.cc
@@ -11,7 +11,7 @@
 
 namespace ui {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OzoneUIControlsTestHelper::ForceUseScreenCoordinatesOnce() {
   NOTREACHED();
 }

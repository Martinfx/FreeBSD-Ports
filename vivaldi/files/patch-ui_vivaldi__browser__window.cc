--- ui/vivaldi_browser_window.cc.orig	2026-08-25 00:00:00 UTC
+++ ui/vivaldi_browser_window.cc
@@ -140,7 +140,7 @@
 #include "ui/wm/core/easy_resize_window_targeter.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #include "chrome/browser/ui/views/theme_profile_key.h"
 #include "ui/linux/linux_ui.h"
@@ -1058,7 +1058,7 @@ void VivaldiBrowserWindow::InitWidget(
 #if BUILDFLAG(IS_MAC)
   // Widget does manual memory management of NativeWidget
   init_params.native_widget = CreateVivaldiNativeWidget(this).release();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   init_params.wm_class_name = shell_integration_linux::GetProgramClassName();
   init_params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   init_params.wayland_app_id = init_params.wm_class_class;
@@ -1102,7 +1102,7 @@ void VivaldiBrowserWindow::InitWidget(
   SetupShellIntegration(create_params);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This is required to make the code work.
   SetThemeProfileForWindow(GetNativeWindow(), GetProfile());
   // Setting the native theme on the top widget improves performance as the

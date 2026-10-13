--- extensions/api/events/vivaldi_ui_events.cc.orig	2026-08-25 00:00:00 UTC
+++ extensions/api/events/vivaldi_ui_events.cc
@@ -21,7 +21,7 @@
 #include "vivaldi/prefs/vivaldi_gen_pref_enums.h"
 #include "vivaldi/prefs/vivaldi_gen_prefs.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/aura/window_tree_host.h"
 #include "ui/ozone/platform_selection.h"
 #include "ui/ozone/public/ozone_platform.h"
@@ -676,7 +676,7 @@ bool VivaldiUIEvents::DoHandleWheelEvent
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 VivaldiBrowserWindow* FindWindowByWidget(gfx::AcceleratedWidget widget) {
   VivaldiBrowserWindow* vivaldi_window = nullptr;
   ForEachCurrentBrowserWindowInterfaceOrderedByActivation(
@@ -720,7 +720,7 @@ void VivaldiUIEvents::DoHandleDragEnd(co
       Profile::FromBrowserContext(web_contents->GetBrowserContext());
 
   // Screen coordinates are not reliable on Wayland
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (strcmp(ui::GetOzonePlatformName(), "wayland") == 0) {
     gfx::AcceleratedWidget widget =
         ui::OzonePlatform::GetInstance()->GetVivaldiDragEndWidget();

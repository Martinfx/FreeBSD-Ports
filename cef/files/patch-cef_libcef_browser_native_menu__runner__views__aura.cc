--- cef/libcef/browser/native/menu_runner_views_aura.cc.orig	2026-11-19 22:06:52 UTC
+++ cef/libcef/browser/native/menu_runner_views_aura.cc
@@ -12,7 +12,7 @@
 #include "ui/base/mojom/menu_source_type.mojom.h"
 #include "ui/gfx/geometry/point.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ozone_buildflags.h"
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
 #include "ui/display/screen.h"
@@ -44,7 +44,7 @@ bool CefMenuRunnerViewsAura::RunContextM
   gfx::Point screen_point = browser->GetScreenPoint(
       gfx::Point(params.x, params.y), /*want_dip_coords=*/true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
   if (browser->IsWindowless() && parent_widget) {
     // On Linux/X11 with OSR, menus are displayed as top-level override-redirect

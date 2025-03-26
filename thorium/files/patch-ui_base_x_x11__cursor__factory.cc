--- ui/base/x/x11_cursor_factory.cc.orig	2023-11-03 10:09:45 UTC
+++ ui/base/x/x11_cursor_factory.cc
@@ -13,7 +13,7 @@
 #include "ui/gfx/geometry/point.h"
 #include "ui/gfx/x/connection.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -70,7 +70,7 @@ scoped_refptr<PlatformCursor> X11CursorFactory::Create
 }
 
 void X11CursorFactory::ObserveThemeChanges() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = LinuxUi::instance();
   DCHECK(linux_ui);
   cursor_theme_observation_.Observe(linux_ui);

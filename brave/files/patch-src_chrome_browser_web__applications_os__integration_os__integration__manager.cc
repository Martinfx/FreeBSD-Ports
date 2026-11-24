--- src/chrome/browser/web_applications/os_integration/os_integration_manager.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/web_applications/os_integration/os_integration_manager.cc
@@ -688,7 +688,7 @@ std::unique_ptr<ShortcutInfo> OsIntegrat
     }
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::vector<WebAppShortcutsMenuItemInfo>& shortcuts_menu_item_infos =
       app->shortcuts_menu_item_infos();
   CHECK_LE(shortcuts_menu_item_infos.size(), kMaxApplicationDockMenuItems,

--- browser/base/content/browser-context.inc.orig	2021-09-19 20:19:43 UTC
+++ browser/base/content/browser-context.inc
@@ -87,9 +87,6 @@
       <menuitem id="context-savelink"
                 data-l10n-id="main-context-menu-save-link"
                 oncommand="gContextMenu.saveLink();"/>
-      <menuitem id="context-savelinktopocket"
-                data-l10n-id="main-context-menu-save-link-to-pocket"
-                oncommand= "Pocket.savePage(gContextMenu.browser, gContextMenu.linkURL);"/>
       <menuitem id="context-copyemail"
                 data-l10n-id="main-context-menu-copy-email"
                 oncommand="gContextMenu.copyEmail();"/>

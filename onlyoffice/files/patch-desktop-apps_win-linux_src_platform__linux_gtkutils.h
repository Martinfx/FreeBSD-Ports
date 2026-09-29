--- desktop-apps/win-linux/src/platform_linux/gtkutils.h.orig	2026-09-28 08:45:35 UTC
+++ desktop-apps/win-linux/src/platform_linux/gtkutils.h
@@ -38,7 +38,7 @@
 
 typedef struct DialogTag {
     GtkWidget* dialog;
-    ulong parent_xid;
+    unsigned long parent_xid;
 } DialogTag;
 
 gboolean set_focus(GtkWidget *dialog);

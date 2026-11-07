--- desktop-apps/win-linux/src/platform_linux/gtkutils.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/platform_linux/gtkutils.h
@@ -41,7 +41,7 @@
 
 typedef struct DialogTag {
     GtkWidget* dialog;
-    ulong parent_xid;
+    unsigned long parent_xid;
 } DialogTag;
 
 gboolean set_focus(GtkWidget *dialog);

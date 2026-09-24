--- desktop-apps/win-linux/src/components/cprintprogress.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/cprintprogress.cpp
@@ -30,7 +30,7 @@
  *
 */
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <gtk/gtk.h>
 # include "cascapplicationmanagerwrapper.h"
 # include "platform_linux/gtkutils.h"
@@ -47,7 +47,7 @@
 #include <QPushButton>
 #include "utils.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static void on_response(GtkDialog*, gint resp_id, gpointer data) {
     switch (resp_id) {
     case GTK_RESPONSE_DELETE_EVENT:

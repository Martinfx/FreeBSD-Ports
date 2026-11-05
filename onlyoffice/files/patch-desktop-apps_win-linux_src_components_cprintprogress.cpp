--- desktop-apps/win-linux/src/components/cprintprogress.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/cprintprogress.cpp
@@ -33,7 +33,7 @@
  * SPDX-License-Identifier: AGPL-3.0-only
  */
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 # include <gtk/gtk.h>
 # include "cascapplicationmanagerwrapper.h"
 # include "platform_linux/gtkutils.h"
@@ -50,7 +50,7 @@
 #include <QPushButton>
 #include "utils.h"
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 static void on_response(GtkDialog*, gint resp_id, gpointer data) {
     switch (resp_id) {
     case GTK_RESPONSE_DELETE_EVENT:
@@ -208,7 +208,7 @@
     bool      useNativeDialog = true;
 
 private:
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     DialogTag tag;
 #endif
 };
@@ -275,7 +275,7 @@
 #endif
     } else {
         pimpl->qtDlg->show();
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
         Utils::processMoreEvents(100);
 #endif
     }

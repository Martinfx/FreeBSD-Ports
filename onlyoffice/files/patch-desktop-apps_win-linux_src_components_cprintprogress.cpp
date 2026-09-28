--- desktop-apps/win-linux/src/components/cprintprogress.cpp.orig	2026-09-28 08:45:35 UTC
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
@@ -204,7 +204,7 @@ public:
     bool      useNativeDialog = true;
 
 private:
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
     DialogTag tag;
 #endif
 };
@@ -271,7 +271,7 @@ void CPrintProgress::startProgress()
 #endif
     } else {
         pimpl->qtDlg->show();
-#ifdef __linux
+#if defined(__linux) || defined(__FreeBSD__)
         Utils::processMoreEvents(100);
 #endif
     }

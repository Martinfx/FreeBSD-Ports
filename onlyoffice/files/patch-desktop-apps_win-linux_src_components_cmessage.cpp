--- desktop-apps/win-linux/src/components/cmessage.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/cmessage.cpp
@@ -49,7 +49,7 @@
 #include <initializer_list>
 #include <memory.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include "platform_linux/gtkmessage.h"
 #else
 # include "platform_win/message.h"
@@ -337,7 +337,7 @@ int QtMsg::showMessage(QWidget *parent,
                           bool   *checkBoxState,
                           const QString &chekBoxText)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     WindowHelper::CParentDisable oDisabler(parent);
 #endif
     QtMsg dlg(parent);

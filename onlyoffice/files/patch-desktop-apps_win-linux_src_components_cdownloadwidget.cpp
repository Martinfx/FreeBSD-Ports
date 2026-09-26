--- desktop-apps/win-linux/src/components/cdownloadwidget.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/cdownloadwidget.cpp
@@ -45,7 +45,7 @@
 #include <QProcess>
 #include <QDesktopServices>
 #include "common/Types.h"
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -73,7 +73,7 @@ struct CDownloadWidget::CDownloadItem
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

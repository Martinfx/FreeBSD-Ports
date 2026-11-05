--- desktop-apps/win-linux/src/components/cdownloadwidget.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/cdownloadwidget.cpp
@@ -48,7 +48,7 @@
 #include <QProcess>
 #include <QDesktopServices>
 #include "common/Types.h"
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -76,7 +76,7 @@
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

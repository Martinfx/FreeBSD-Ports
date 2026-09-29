--- desktop-apps/win-linux/src/components/cmenu.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/cmenu.cpp
@@ -36,7 +36,7 @@
 #include <QPainter>
 #include <QLayout>
 #include <QAction>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -52,7 +52,7 @@
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

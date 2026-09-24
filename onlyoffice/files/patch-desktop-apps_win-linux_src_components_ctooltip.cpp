--- desktop-apps/win-linux/src/components/ctooltip.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/components/ctooltip.cpp
@@ -38,7 +38,7 @@
 #include <QTimer>
 #include <QCursor>
 #include <QLineF>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -48,7 +48,7 @@
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

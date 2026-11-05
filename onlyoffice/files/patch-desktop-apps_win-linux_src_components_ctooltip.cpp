--- desktop-apps/win-linux/src/components/ctooltip.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/ctooltip.cpp
@@ -41,7 +41,7 @@
 #include <QTimer>
 #include <QCursor>
 #include <QLineF>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -51,7 +51,7 @@
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

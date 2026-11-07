--- desktop-apps/win-linux/src/components/cmenu.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/components/cmenu.cpp
@@ -41,7 +41,7 @@
 #include <QAction>
 #include <qtcomp/qnativeevent.h>
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 # include <QX11Info>
 #endif
 
@@ -57,7 +57,7 @@
 
 static bool isCompositingEnabled()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return QX11Info::isCompositingManagerRunning();
 #else
     return true;

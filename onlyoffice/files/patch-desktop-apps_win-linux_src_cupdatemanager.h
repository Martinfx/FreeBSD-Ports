--- desktop-apps/win-linux/src/cupdatemanager.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/cupdatemanager.h
@@ -36,7 +36,7 @@
 #include <QObject>
 #include <QTimer>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # define __STDC_WANT_LIB_EXT1__ 1
 #endif
 #include <ctime>

--- desktop-apps/win-linux/src/cupdatemanager.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/cupdatemanager.h
@@ -39,7 +39,7 @@
 #include <QObject>
 #include <QTimer>
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 # define __STDC_WANT_LIB_EXT1__ 1
 #endif
 #include <ctime>

--- desktop-apps/win-linux/src/cprintdata.cpp.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/cprintdata.cpp
@@ -40,7 +40,7 @@
 #include <QSettings>
 #include <thread>
 #include <cmath>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <cups/cups.h>
 # include <cups/ppd.h>
 #endif

--- desktop-apps/win-linux/src/cprintdata.cpp.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/cprintdata.cpp
@@ -43,7 +43,7 @@
 #include <QSettings>
 #include <thread>
 #include <cmath>
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include <cups/cups.h>
 # include <cups/ppd.h>
 #endif

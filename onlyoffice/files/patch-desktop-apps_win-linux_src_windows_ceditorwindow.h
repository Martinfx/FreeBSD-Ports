--- desktop-apps/win-linux/src/windows/ceditorwindow.h.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow.h
@@ -36,7 +36,7 @@
 #ifndef CEDITORWINDOW_H
 #define CEDITORWINDOW_H
 
-#ifdef __linux__
+#if (defined(__linux__) || defined(__FreeBSD__)) || defined(__FreeBSD__)
 # include "windows/platform_linux/cwindowplatform.h"
 #else
 # include "windows/platform_win/cwindowplatform.h"

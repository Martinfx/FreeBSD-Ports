--- desktop-apps/win-linux/src/windows/ceditorwindow.h.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/src/windows/ceditorwindow.h
@@ -33,7 +33,7 @@
 #ifndef CEDITORWINDOW_H
 #define CEDITORWINDOW_H
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 # include "windows/platform_linux/cwindowplatform.h"
 #else
 # include "windows/platform_win/cwindowplatform.h"

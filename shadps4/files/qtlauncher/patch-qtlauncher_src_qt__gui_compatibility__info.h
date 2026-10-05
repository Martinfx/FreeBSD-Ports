--- qtlauncher/src/qt_gui/compatibility_info.h.orig	2026-10-02 19:05:42 UTC
+++ qtlauncher/src/qt_gui/compatibility_info.h
@@ -26,7 +26,7 @@
     Unknown,
     Linux,
     macOS,
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
     Linux = 0,
     Unknown,
     Win32,

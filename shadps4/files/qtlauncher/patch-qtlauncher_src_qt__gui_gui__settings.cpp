--- qtlauncher/src/qt_gui/gui_settings.cpp.orig	2026-10-02 19:05:42 UTC
+++ qtlauncher/src/qt_gui/gui_settings.cpp
@@ -19,7 +19,7 @@
     exeName = "shadPS4.exe";
 #elif defined(Q_OS_LINUX)
     exeName = "Shadps4-sdl.AppImage";
-#elif defined(Q_OS_MACOS)
+#elif defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
     exeName = "shadps4";
 #endif
 

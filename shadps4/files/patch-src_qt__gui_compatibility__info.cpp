--- src/qt_gui/compatibility_info.cpp.orig	2025-04-06 14:08:28 UTC
+++ src/qt_gui/compatibility_info.cpp
@@ -88,6 +88,8 @@ CompatibilityEntry CompatibilityInfoClass::GetCompatib
         current_os = "os-macOS";
 #elif defined(Q_OS_LINUX)
         current_os = "os-linux";
+#elif defined(Q_OS_FREEBSD)
+	current_os = "os_freebsd";
 #else
         current_os = "os-unknown";
 #endif

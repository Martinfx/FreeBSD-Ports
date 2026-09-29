--- core/DesktopEditor/graphics/pro/graphics.pro.orig	2025-09-24 06:08:05 UTC
+++ core/DesktopEditor/graphics/pro/graphics.pro
@@ -22,6 +22,12 @@ ADD_DEPENDENCY(UnicodeConverter, kernel)
 
 ADD_DEPENDENCY(UnicodeConverter, kernel)
 
+core_freebsd {
+    LIBS += -lharfbuzz
+    DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
+
 core_windows {
 	LIBS += -lAdvapi32
 	LIBS += -lShell32

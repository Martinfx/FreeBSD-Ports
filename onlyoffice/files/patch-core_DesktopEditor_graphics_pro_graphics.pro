--- core/DesktopEditor/graphics/pro/graphics.pro.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/graphics/pro/graphics.pro
@@ -55,6 +55,12 @@
 
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

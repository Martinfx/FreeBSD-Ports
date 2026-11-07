--- core/DesktopEditor/graphics/pro/raster.pri.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/graphics/pro/raster.pri
@@ -47,6 +47,12 @@
 	MNG_STORE_CHUNKS\
 	MNG_ERROR_TELLTALE
 
+core_freebsd {
+    DEFINES += \
+    HAVE_UNISTD_H
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
+
 core_linux {
 	DEFINES += HAVE_UNISTD_H HAVE_FCNTL_H
 	QMAKE_CXXFLAGS += -Wno-narrowing

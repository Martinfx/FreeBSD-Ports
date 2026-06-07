--- core/DesktopEditor/graphics/pro/raster.pri.orig	2025-09-24 06:08:05 UTC
+++ core/DesktopEditor/graphics/pro/raster.pri
@@ -14,6 +14,12 @@ DEFINES += \
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

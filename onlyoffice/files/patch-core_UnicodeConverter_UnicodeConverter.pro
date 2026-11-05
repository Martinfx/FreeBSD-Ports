--- core/UnicodeConverter/UnicodeConverter.pro.orig	2026-11-05 00:00:00 UTC
+++ core/UnicodeConverter/UnicodeConverter.pro
@@ -46,6 +46,12 @@
 
 DEFINES += UNICODECONVERTER_USE_DYNAMIC_LIBRARY
 
+core_freebsd {
+    CONFIG += c++17
+    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
+    QMAKE_LFLAGS += -Wl,--disable-new-dtags
+}
+
 core_linux {    
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags

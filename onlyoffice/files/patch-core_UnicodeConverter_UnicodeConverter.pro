--- core/UnicodeConverter/UnicodeConverter.pro.orig	2025-09-24 09:45:54 UTC
+++ core/UnicodeConverter/UnicodeConverter.pro
@@ -13,6 +13,12 @@ DEFINES += UNICODECONVERTER_USE_DYNAMIC_LIBRARY
 
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

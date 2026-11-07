--- core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro.orig	2026-11-05 00:00:00 UTC
+++ core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro
@@ -89,6 +89,11 @@
     LIBS += -lws2_32
 }
 
+core_freebsd {
+    LIBS += -lz -pthread
+    QMAKE_LFLAGS += -Wl,--rpath=./
+}
+
 core_linux {
     LIBS += -lz -pthread -ldl
 }

--- core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro.orig	2025-09-24 09:41:11 UTC
+++ core/OfficeCryptReader/ooxml_crypt/ooxml_crypt.pro
@@ -56,6 +56,11 @@ core_windows {
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

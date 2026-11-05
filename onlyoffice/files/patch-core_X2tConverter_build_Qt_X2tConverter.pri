--- core/X2tConverter/build/Qt/X2tConverter.pri.orig	2026-11-05 00:00:00 UTC
+++ core/X2tConverter/build/Qt/X2tConverter.pri
@@ -172,6 +172,10 @@
 core_windows {
     LIBS += -lAdvapi32
 }
+core_freebsd {
+    LIBS += -liconv -lharfbuzz
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 ########################################################
 
 core_mac | core_ios {

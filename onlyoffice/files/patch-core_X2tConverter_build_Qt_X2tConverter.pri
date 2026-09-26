--- core/X2tConverter/build/Qt/X2tConverter.pri.orig	2026-09-24 21:59:09 UTC
+++ core/X2tConverter/build/Qt/X2tConverter.pri
@@ -145,5 +145,9 @@ include($$PWD/../../../Common/3dParty/bo
 core_windows {
     LIBS += -lAdvapi32
 }
+core_freebsd {
+    LIBS += -liconv -lharfbuzz
+    QMAKE_CXXFLAGS += -Wno-narrowing
+}
 ########################################################
 

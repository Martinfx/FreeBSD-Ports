--- core/Common/3dParty/html/gumbo.pri.orig	2026-11-05 00:00:00 UTC
+++ core/Common/3dParty/html/gumbo.pri
@@ -1,6 +1,7 @@
 INCLUDEPATH += $$PWD
 DEPENDPATH += $$PWD
 
+core_freebsd:QMAKE_CFLAGS += -std=c99
 core_linux:QMAKE_CFLAGS += -std=c99
 core_windows:INCLUDEPATH += $$PWD/gumbo-parser/visualc/include
 

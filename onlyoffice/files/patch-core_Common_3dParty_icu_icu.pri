--- core/Common/3dParty/icu/icu.pri.orig	2026-11-05 00:00:00 UTC
+++ core/Common/3dParty/icu/icu.pri
@@ -18,6 +18,13 @@
     LIBS        += -L$$ICU_LIBS_PATH_WIN -licuuc
 }
 
+core_freebsd {
+    INCLUDEPATH += %%LOCALBASE%%/include
+
+    LIBS        += %%LOCALBASE%%/lib/libicuuc.so
+    LIBS        += %%LOCALBASE%%/lib/libicudata.so
+}
+
 core_linux {
     INCLUDEPATH += $$PWD/$$CORE_BUILDS_PLATFORM_PREFIX/build/include
 

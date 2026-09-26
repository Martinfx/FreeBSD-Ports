--- core/Common/3dParty/icu/icu.pri.orig	2025-09-23 22:50:01 UTC
+++ core/Common/3dParty/icu/icu.pri
@@ -10,6 +10,13 @@ core_windows {
     LIBS        += -L$$PWD/$$CORE_BUILDS_PLATFORM_PREFIX/build -licuuc
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
 

--- desktop-sdk/ChromiumBasedEditors/lib/cef_pri_107/cef_base.pri.orig	2025-09-26 14:55:44 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/cef_pri_107/cef_base.pri
@@ -650,6 +650,13 @@ HEADERS += \
     $$CEF_SRC_PATH/include/internal/cef_types_linux.h
 }
 
+core_freebsd {
+HEADERS += \
+    $$CEF_SRC_PATH/include/internal/cef_freebsd.h \
+    $$CEF_SRC_PATH/include/internal/cef_types_linux.h
+}
+
+
 core_mac {
 HEADERS += \
     $$CEF_SRC_PATH/include/base/cef_scoped_typeref_mac.h \
@@ -706,7 +713,7 @@ LIBS += \
 
 }
 
-core_linux {
+core_freebsd {
 
 LIBS += -L$$PWD/../../../../core/Common/3dParty/cef/$$CORE_BUILDS_PLATFORM_PREFIX/build_107 -lcef
 

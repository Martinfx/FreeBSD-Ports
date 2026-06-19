--- desktop-sdk/ChromiumBasedEditors/lib/cef_pri/cef_base.pri.orig	2025-09-24 17:22:17 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/cef_pri/cef_base.pri
@@ -651,9 +651,9 @@ HEADERS += \
     $$CEF_SRC_PATH/include/internal/cef_win.h
 }
 
-core_linux {
+core_freebsd {
 HEADERS += \
-    $$CEF_SRC_PATH/include/internal/cef_linux.h \
+    $$CEF_SRC_PATH/include/internal/cef_freebsd.h \
     $$CEF_SRC_PATH/include/internal/cef_types_linux.h
 }
 
@@ -713,7 +713,7 @@ LIBS += \
 
 }
 
-core_linux {
+core_freebsd {
 
 LIBS += -L$$PWD/../../../../core/Common/3dParty/cef/$$CORE_BUILDS_PLATFORM_PREFIX/build -lcef
 

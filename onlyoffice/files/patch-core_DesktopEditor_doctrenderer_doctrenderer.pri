--- core/DesktopEditor/doctrenderer/doctrenderer.pri.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/doctrenderer/doctrenderer.pri
@@ -56,6 +56,10 @@
 #CONFIG += v8_version_60
 core_android:DEFINES += DISABLE_MEMORY_LIMITATION
 
+core_freebsd {
+    LIBS += -lexecinfo
+}
+
 HEADERS += \
 	$$PWD_CUR/config.h \
 	$$PWD_CUR/editors.h \

--- desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib.pri.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib.pri
@@ -5,7 +5,9 @@
 PWD_ROOT_DIR = $$PWD
 include($$CORE_ROOT_DIR/Common/base.pri)
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
 	DEFINES += QFILEDIALOG_DONTUSENATIVEDIALOG
 }
 

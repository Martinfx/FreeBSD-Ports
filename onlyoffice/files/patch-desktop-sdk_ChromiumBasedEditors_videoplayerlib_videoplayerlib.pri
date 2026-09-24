--- desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib.pri.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib.pri
@@ -5,7 +5,9 @@ CORE_ROOT_DIR = $$PWD/../../../core
 PWD_ROOT_DIR = $$PWD
 include($$CORE_ROOT_DIR/Common/base.pri)
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
 	DEFINES += QFILEDIALOG_DONTUSENATIVEDIALOG
 }
 

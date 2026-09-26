--- desktop-sdk/ChromiumBasedEditors/lib/qt_wrapper/qtascdocumentscore.pro.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/qt_wrapper/qtascdocumentscore.pro
@@ -38,7 +38,9 @@ core_windows {
 	build_xp:DESTDIR=$$DESTDIR/xp
 }
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
     !greaterThan(QT_MAJOR_VERSION, 5) {
         QT += x11extras
     } else {

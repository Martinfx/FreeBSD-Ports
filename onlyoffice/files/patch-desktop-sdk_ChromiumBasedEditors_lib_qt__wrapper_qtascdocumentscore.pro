--- desktop-sdk/ChromiumBasedEditors/lib/qt_wrapper/qtascdocumentscore.pro.orig	2025-09-26 18:17:17 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/qt_wrapper/qtascdocumentscore.pro
@@ -38,7 +38,7 @@ core_windows {
 	build_xp:DESTDIR=$$DESTDIR/xp
 }
 
-core_linux {
+core_freebsd {
     !greaterThan(QT_MAJOR_VERSION, 5) {
         QT += x11extras
     } else {

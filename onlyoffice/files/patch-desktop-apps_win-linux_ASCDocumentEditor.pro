--- desktop-apps/win-linux/ASCDocumentEditor.pro.orig	2026-11-07 00:00:00 UTC
+++ desktop-apps/win-linux/ASCDocumentEditor.pro
@@ -50,7 +50,7 @@
     OTHER_FILES += $$PWD/version.rc
 }
 
-core_linux {
+core_linux|core_freebsd {
     GLIB_RESOURCE_FILES += $$PWD/res/gresource.xml
 
     glib_resources.name = gresource

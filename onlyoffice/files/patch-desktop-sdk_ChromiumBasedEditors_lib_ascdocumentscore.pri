--- desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri.orig	2025-09-24 17:18:42 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri
@@ -181,7 +181,7 @@ core_mac {
 	DEFINES += NO_SUPPORT_MEDIA_PLAYER
 }
 
-core_linux {
+core_freebsd {
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags

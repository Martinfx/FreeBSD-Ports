--- desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore_helper.pro.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore_helper.pro
@@ -25,7 +25,9 @@ core_windows {
 	}
 }
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
 	QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
 	QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
 

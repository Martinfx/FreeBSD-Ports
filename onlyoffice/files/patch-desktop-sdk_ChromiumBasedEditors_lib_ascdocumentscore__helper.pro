--- desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore_helper.pro.orig	2025-09-24 17:20:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore_helper.pro
@@ -25,7 +25,7 @@ core_windows {
 	}
 }
 
-core_linux {
+core_freebsd {
 	QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
 	QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
 

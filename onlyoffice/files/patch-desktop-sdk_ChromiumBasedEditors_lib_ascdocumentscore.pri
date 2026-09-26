--- desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri
@@ -59,6 +59,11 @@ build_xp {
         }
     }
 
+    core_freebsd {
+        # CEF from www/cef, see cef_pri_freebsd
+        CEF_PROJECT_PRI=$$PWD/cef_pri_freebsd
+    }
+
     include($$CEF_PROJECT_PRI/cef_base.pri)
     include($$CEF_PROJECT_PRI/cef_client.pri)
 }
@@ -181,7 +186,9 @@ core_mac {
 	DEFINES += NO_SUPPORT_MEDIA_PLAYER
 }
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags

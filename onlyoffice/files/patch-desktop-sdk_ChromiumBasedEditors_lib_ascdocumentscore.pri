--- desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri.orig	2026-11-05 00:00:00 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/ascdocumentscore.pri
@@ -64,6 +64,11 @@
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
@@ -256,7 +261,9 @@
 	QMAKE_BUNDLE_DATA += PLAYER_BUTTON_ICONS
 }
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
     QMAKE_LFLAGS += -Wl,--disable-new-dtags

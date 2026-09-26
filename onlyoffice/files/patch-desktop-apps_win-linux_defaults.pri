--- desktop-apps/win-linux/defaults.pri.orig	2026-09-24 21:58:50 UTC
+++ desktop-apps/win-linux/defaults.pri
@@ -186,17 +186,19 @@ CMD_IN_HELP_URL = $$join(URL_WEBAPPS_HEL
 
 PLATFORM_BUILD=$$CORE_BUILDS_PLATFORM_PREFIX
 
-core_linux:LIBS += -Wl,-unresolved-symbols=ignore-in-shared-libs
+core_linux|core_freebsd:LIBS += -Wl,-unresolved-symbols=ignore-in-shared-libs
 
 ADD_DEPENDENCY(PdfFile, DjVuFile, XpsFile, UnicodeConverter, hunspell, ooxmlsignature, kernel, kernel_network, graphics, ascdocumentscore, qtascdocumentscore)
 include($$CORE_ROOT_DIR/../desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib_deps.pri)
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
     QT += network x11extras
 
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
-    QMAKE_LFLAGS += -static-libstdc++ -static-libgcc
+    core_linux:QMAKE_LFLAGS += -static-libstdc++ -static-libgcc
 
     INCLUDEPATH += $$PWD/extras/update-daemon/src/classes
 
@@ -242,8 +244,11 @@ core_linux {
         PKGCONFIG += dbus-1
     }
 
-    LIBS += $$CORE_3DPARTY_PATH/icu/$$PLATFORM_BUILD/build/libicuuc.so.58
-    LIBS += $$CORE_3DPARTY_PATH/icu/$$PLATFORM_BUILD/build/libicudata.so.58
+    core_linux {
+        LIBS += $$CORE_3DPARTY_PATH/icu/$$PLATFORM_BUILD/build/libicuuc.so.58
+        LIBS += $$CORE_3DPARTY_PATH/icu/$$PLATFORM_BUILD/build/libicudata.so.58
+    }
+    core_freebsd:LIBS += -licuuc -licudata
 
     DEFINES += DOCUMENTSCORE_OPENSSL_SUPPORT
 }

--- desktop-apps/win-linux/defaults.pri.orig	2026-11-05 00:00:00 UTC
+++ desktop-apps/win-linux/defaults.pri
@@ -207,17 +207,20 @@
 
 PLATFORM_BUILD=$$CORE_BUILDS_PLATFORM_PREFIX
 
-core_linux:LIBS += -Wl,-unresolved-symbols=ignore-in-shared-libs
+core_linux|core_freebsd:LIBS += -Wl,-unresolved-symbols=ignore-in-shared-libs
 
 ADD_DEPENDENCY(PdfFile, DjVuFile, XpsFile, OFDFile, UnicodeConverter, hunspell, ooxmlsignature, kernel, kernel_network, graphics, ascdocumentscore, qtascdocumentscore)
 include($$CORE_ROOT_DIR/../desktop-sdk/ChromiumBasedEditors/videoplayerlib/videoplayerlib_deps.pri)
 
-core_linux {
+core_freebsd:DEFINES += LINUX _LINUX
+
+core_linux|core_freebsd {
     QT += network x11extras dbus
+    core_freebsd:QT += concurrent
 
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
     QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/converter\'"
-    QMAKE_LFLAGS += -static-libstdc++ -static-libgcc
+    core_linux:QMAKE_LFLAGS += -static-libstdc++ -static-libgcc
 
     INCLUDEPATH += $$PWD/extras/update-daemon/src/classes
 

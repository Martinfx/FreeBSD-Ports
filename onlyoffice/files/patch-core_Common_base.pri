--- core/Common/base.pri.orig	2025-09-23 22:49:53 UTC
+++ core/Common/base.pri
@@ -102,6 +102,14 @@ android {
 	DEFINES += __ANDROID__ LINUX _LINUX _ARM_ALIGN_
 }
 
+freebsd-clang {
+    message("freebsd-clang")
+    CONFIG += core_freebsd
+    CONFIG += core_freebsd_64
+    QMAKE_CC = %%CC%%
+    QMAKE_CXX = %%CXX%%
+}
+
 win32:contains(QMAKE_TARGET.arch, x86_64): {
 	CONFIG += core_win_64
 }
@@ -197,6 +205,14 @@ core_win_64 {
 	DEFINES += WIN64 _WIN64
 }
 
+core_freebsd {
+    equals(TEMPLATE, app) {
+        QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"
+        QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/system\'"
+        QMAKE_LFLAGS += -Wl,--disable-new-dtags
+    }
+}
+
 core_linux {
 	DEFINES += LINUX _LINUX
 }
@@ -256,6 +272,10 @@ core_windows {
 			core_win_32:QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
 		}
 	}
+}
+
+core_freebsd_64 {
+    CORE_BUILDS_PLATFORM_PREFIX = freebsd_64
 }
 
 core_linux {

--- core/Common/base.pri.orig	2026-11-05 00:00:00 UTC
+++ core/Common/base.pri
@@ -148,6 +148,14 @@
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
@@ -248,6 +256,14 @@
     return(false)
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
 
@@ -366,6 +382,10 @@
 	}
 }
 
+core_freebsd_64 {
+    CORE_BUILDS_PLATFORM_PREFIX = freebsd_64
+}
+
 core_linux {
 	equals(TEMPLATE, app) {
 		QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN\'"

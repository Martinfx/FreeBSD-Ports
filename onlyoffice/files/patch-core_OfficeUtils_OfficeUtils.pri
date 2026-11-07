--- core/OfficeUtils/OfficeUtils.pri.orig	2026-11-05 00:00:00 UTC
+++ core/OfficeUtils/OfficeUtils.pri
@@ -31,6 +31,9 @@
 #
 # SPDX-License-Identifier: AGPL-3.0-only
 
+core_freebsd {
+    QMAKE_CXXFLAGS += -Wall -Wno-ignored-qualifiers
+}
 core_linux {
     QMAKE_CXXFLAGS += -Wall -Wno-ignored-qualifiers
 }

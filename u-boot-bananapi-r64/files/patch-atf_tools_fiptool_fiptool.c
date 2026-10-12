--- atf/tools/fiptool/fiptool.c.orig	2026-05-21 08:05:04 UTC
+++ atf/tools/fiptool/fiptool.c
@@ -4,6 +4,8 @@
  * SPDX-License-Identifier: BSD-3-Clause
  */
 
+#define __BSD_VISIBLE 1
+
 #ifdef __linux__
 #include <sys/mount.h>
 #endif

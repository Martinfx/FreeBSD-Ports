--- src/base/posix/sysctl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/base/posix/sysctl.cc
@@ -4,6 +4,7 @@
 
 #include "base/posix/sysctl.h"
 
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 #include <initializer_list>

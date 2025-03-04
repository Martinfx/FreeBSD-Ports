--- src/util/atomic.h.orig	2025-03-04 16:01:33 UTC
+++ src/util/atomic.h
@@ -5,6 +5,8 @@
 #ifndef __UTIL_ATOMIC_H__
 #define __UTIL_ATOMIC_H__
 
+#include "atomic_ops.h"
+
 #ifndef __KERNEL_GPU__
 
 /* Using atomic ops header from Blender. */

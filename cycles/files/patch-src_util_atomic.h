--- src/util/atomic.h.orig	2025-10-18 14:00:18 UTC
+++ src/util/atomic.h
@@ -4,6 +4,8 @@
 
 #pragma once
 
+#include "atomic_ops.h"
+
 #ifndef __KERNEL_GPU__
 
 /* Using atomic ops header from Blender. */

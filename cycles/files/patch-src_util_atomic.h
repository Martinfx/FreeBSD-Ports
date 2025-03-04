--- src/util/atomic.h.orig	2025-03-04 14:43:48 UTC
+++ src/util/atomic.h
@@ -21,7 +21,7 @@
 #  define ccl_barrier(flags) ((void)0)
 
 #else /* __KERNEL_GPU__ */
-
+#  include "atomic_ops.h"
 #  ifndef __KERNEL_ONEAPI__
 #    define atomic_fetch_and_add_uint32_shared atomic_fetch_and_add_uint32
 #  endif

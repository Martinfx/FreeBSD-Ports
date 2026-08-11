--- physx/include/extensions/PxDefaultAllocator.h.orig	2024-07-05 09:09:12 UTC
+++ physx/include/extensions/PxDefaultAllocator.h
@@ -40,7 +40,7 @@
 
 #include <stdlib.h>
 
-#if PX_WINDOWS_FAMILY || PX_LINUX_FAMILY || PX_SWITCH
+#if PX_WINDOWS_FAMILY || PX_LINUX_FAMILY || PX_SWITCH || PX_FREEBSD
 #include <malloc.h>
 #endif
 
@@ -60,7 +60,7 @@ PX_FORCE_INLINE void platformAlignedFree(void* ptr)
 {
 	_aligned_free(ptr);
 }
-#elif PX_LINUX_FAMILY || PX_SWITCH
+#elif PX_LINUX_FAMILY || PX_SWITCH || PX_FREEBSD
 PX_FORCE_INLINE void* platformAlignedAlloc(size_t size)
 {
 	return ::memalign(16, size);

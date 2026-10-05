--- src/common/slot_vector.cpp.orig	2026-10-02 12:00:00 UTC
+++ src/common/slot_vector.cpp
@@ -17,8 +17,12 @@
     void* const base = VirtualAlloc(nullptr, size, MEM_RESERVE, PAGE_NOACCESS);
     ASSERT(base);
 #else
-    void* const base =
-        mmap(nullptr, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
+    int flags = MAP_PRIVATE | MAP_ANONYMOUS;
+#ifdef MAP_NORESERVE
+    // Not available on FreeBSD, which does not reserve swap for PROT_NONE mappings anyway.
+    flags |= MAP_NORESERVE;
+#endif
+    void* const base = mmap(nullptr, size, PROT_NONE, flags, -1, 0);
     ASSERT(base != MAP_FAILED);
 #endif
     return base;

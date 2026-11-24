--- src/base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2026-11-24 12:50:30 UTC
+++ src/base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -279,7 +279,7 @@ bool DecommitAndZeroSystemPages(void* ad
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;

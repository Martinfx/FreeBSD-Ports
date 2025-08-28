--- src/core/address_space.cpp.orig	2025-07-06 18:24:57 UTC
+++ src/core/address_space.cpp
@@ -374,7 +374,7 @@ struct AddressSpace::Impl {
         user_size = UserSize;
 
         constexpr int protection_flags = PROT_READ | PROT_WRITE;
-        constexpr int base_map_flags = MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
+        constexpr int base_map_flags = MAP_PRIVATE | MAP_ANONYMOUS;
 #if defined(__APPLE__) && defined(ARCH_X86_64)
         // On ARM64 Macs under Rosetta 2, we run into limitations due to the commpage from
         // 0xFC0000000 - 0xFFFFFFFFF and the GPU carveout region from 0x1000000000 - 0x6FFFFFFFFF.
@@ -440,7 +440,9 @@ struct AddressSpace::Impl {
         }
         shm_unlink(shm_path.c_str());
 #else
-        madvise(virtual_base, virtual_size, MADV_HUGEPAGE);
+#ifdef __linux__
+	madvise(virtual_base, virtual_size, MADV_HUGEPAGE);
+#endif
 
         backing_fd = memfd_create("BackingDmem", 0);
         if (backing_fd < 0) {

--- src/core/address_space.cpp.orig	2026-06-01 15:47:16 UTC
+++ src/core/address_space.cpp
@@ -655,7 +655,13 @@
             mmap(reinterpret_cast<void*>(USER_MIN), user_size, protection_flags, map_flags, -1, 0));
 #else
         const auto virtual_size = system_managed_size + system_reserved_size + user_size;
-#if defined(ARCH_X86_64) && !defined(__FreeBSD__)
+#if defined(ARCH_X86_64)
+#if defined(__FreeBSD__)
+        // The executable is linked at 0x700000000000 and ASLR is disabled through the ELF
+        // feature control note, so rtld, libc and the heap all live above the guest range.
+        // MAP_EXCL makes mmap fail instead of silently replacing an existing mapping.
+        map_flags |= MAP_EXCL;
+#endif
         const auto virtual_base =
             reinterpret_cast<u8*>(mmap(reinterpret_cast<void*>(SYSTEM_MANAGED_MIN), virtual_size,
                                        protection_flags, map_flags, -1, 0));
@@ -663,7 +669,6 @@
         system_reserved_base = reinterpret_cast<u8*>(SYSTEM_RESERVED_MIN);
         user_base = reinterpret_cast<u8*>(USER_MIN);
 #else
-        // FreeBSD can't stand MAP_FIXED or it may overwrite mmap() itself!
         // Map memory wherever possible and instruction translation can handle offsetting to the
         // base.
         map_flags &= ~MAP_FIXED;
@@ -677,6 +682,10 @@
         if (system_managed_base == MAP_FAILED || system_reserved_base == MAP_FAILED ||
             user_base == MAP_FAILED) {
             LOG_CRITICAL(Kernel_Vmm, "mmap failed: {}", strerror(errno));
+#if defined(__FreeBSD__)
+            LOG_CRITICAL(Kernel_Vmm, "The PS4 address range is already in use, make sure ASLR "
+                                     "is disabled for shadps4 (elfctl -e +noaslr)");
+#endif
             throw std::bad_alloc{};
         }
 
@@ -690,7 +699,7 @@
                  fmt::ptr(user_base + user_size - 1));
 
         const VAddr system_managed_addr = reinterpret_cast<VAddr>(system_managed_base);
-        const VAddr system_reserved_addr = reinterpret_cast<VAddr>(system_managed_base);
+        const VAddr system_reserved_addr = reinterpret_cast<VAddr>(system_reserved_base);
         const VAddr user_addr = reinterpret_cast<VAddr>(user_base);
         m_free_regions.insert({system_managed_addr, system_managed_addr + system_managed_size});
         m_free_regions.insert({system_reserved_addr, system_reserved_addr + system_reserved_size});

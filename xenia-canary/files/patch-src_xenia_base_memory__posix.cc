--- src/xenia/base/memory_posix.cc.orig
+++ src/xenia/base/memory_posix.cc
@@ -36,6 +36,16 @@
 #include "xenia/base/main_android.h"
 #endif
 
+#if XE_PLATFORM_FREEBSD
+#include <sys/types.h>
+// <sys/user.h> pulls in struct cv from <sys/condvar.h>, which would clash with
+// the cvar namespace.
+#define cv freebsd_sys_cv
+#include <sys/user.h>
+#undef cv
+#include <libutil.h>
+#endif
+
 #if XE_PLATFORM_GNU_LINUX
 #ifndef MFD_EXEC
 #define MFD_EXEC 0x0010U
@@ -165,6 +175,9 @@ void* AllocFixed(void* base_address, size_t length,
     }
 #ifdef MAP_FIXED_NOREPLACE
     flags |= MAP_FIXED_NOREPLACE;
+#elif defined(MAP_EXCL)
+    // FreeBSD: fail instead of replacing an existing mapping.
+    flags |= MAP_FIXED | MAP_EXCL;
 #endif
   }
 
@@ -218,6 +231,46 @@ bool Protect(void* base_address, size_t length, PageAccess access,
   return mprotect(base_address, length, prot) == 0;
 }
 
+#if XE_PLATFORM_FREEBSD
+static PageAccess ToXeniaProtectFlags(int kve_protection) {
+  const char protection[] = {
+      (kve_protection & KVME_PROT_READ) ? 'r' : '-',
+      (kve_protection & KVME_PROT_WRITE) ? 'w' : '-',
+      (kve_protection & KVME_PROT_EXEC) ? 'x' : '-', '\0'};
+  return ToXeniaProtectFlags(protection);
+}
+
+bool QueryProtect(void* base_address, size_t& length, PageAccess& access_out) {
+  // There is no /proc/self/maps unless linprocfs is mounted, ask the kernel
+  // for the memory map with the kern.proc.vmmap sysctl instead.
+  int count = 0;
+  struct kinfo_vmentry* entries = kinfo_getvmmap(getpid(), &count);
+  if (!entries) {
+    return false;
+  }
+  const auto address = reinterpret_cast<uintptr_t>(base_address);
+  bool found = false;
+  for (int i = 0; i < count; ++i) {
+    if (entries[i].kve_start > address || entries[i].kve_end <= address) {
+      continue;
+    }
+    access_out = ToXeniaProtectFlags(entries[i].kve_protection);
+    // Look at the next consecutive mappings
+    uint64_t region_end = entries[i].kve_end;
+    for (int j = i + 1; j < count && entries[j].kve_start == region_end &&
+                        ToXeniaProtectFlags(entries[j].kve_protection) ==
+                            access_out;
+         ++j) {
+      region_end = entries[j].kve_end;
+    }
+    length = region_end - address;
+    found = true;
+    break;
+  }
+  free(entries);
+  return found;
+}
+#else
 bool QueryProtect(void* base_address, size_t& length, PageAccess& access_out) {
   // No generic POSIX solution exists. The Linux solution should work on all
   // Linux kernel based OS, including Android.
@@ -265,6 +318,7 @@ bool QueryProtect(void* base_address, size_t& length, PageAccess& access_out) {
   memory_maps.close();
   return false;
 }
+#endif  // XE_PLATFORM_FREEBSD
 
 FileMappingHandle CreateFileMappingHandle(const std::filesystem::path& path,
                                           size_t length, PageAccess access,
@@ -386,6 +440,9 @@ void* MapFileView(FileMappingHandle handle, void* base_address, size_t length,
   if (base_address != nullptr) {
 #ifdef MAP_FIXED_NOREPLACE
     flags |= MAP_FIXED_NOREPLACE;
+#elif defined(MAP_EXCL)
+    // FreeBSD: fail instead of replacing an existing mapping.
+    flags |= MAP_FIXED | MAP_EXCL;
 #endif
   }
 

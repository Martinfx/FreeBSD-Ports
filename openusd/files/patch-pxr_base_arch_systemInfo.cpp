--- pxr/base/arch/systemInfo.cpp.orig	2026-02-23 22:54:59 UTC
+++ pxr/base/arch/systemInfo.cpp
@@ -21,6 +21,13 @@
     #include <sys/stat.h>
     #include <unistd.h>
 
+#elif defined(ARCH_OS_FREEBSD)
+
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+    #include <errno.h>
+    #include <unistd.h>
+
 #elif defined(ARCH_OS_DARWIN)
 
     #include <unistd.h>
@@ -128,6 +135,31 @@ ArchGetExecutablePath()
                 }
             });
 
+#elif defined(ARCH_OS_FREEBSD)
+
+    // On FreeBSD the executable path is retrieved with the
+    // kern.proc.pathname sysctl, which does not require procfs to be
+    // mounted (unlike /proc/curproc/file).
+    return
+        _DynamicSizedRead(ARCH_PATH_MAX,
+            [](char* buffer, size_t* size) {
+                int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+                size_t len = *size;
+                if (sysctl(mib, 4, buffer, &len, NULL, 0) == 0) {
+                    return true;
+                }
+                if (errno == ENOMEM) {
+                    // Try iterating on the size.
+                    *size *= 2;
+                }
+                else {
+                    ARCH_WARNING("Unable to read kern.proc.pathname to "
+                                 "obtain executable path");
+                    *size = std::numeric_limits<size_t>::max();
+                }
+                return false;
+            });
+
 #elif defined(ARCH_OS_DARWIN)
 
     // On Darwin _NSGetExecutablePath() returns the executable path.
@@ -180,7 +212,7 @@ int
 ArchGetPageSize()
 {
 #if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN) || \
-    defined(ARCH_OS_WASM_VM)
+    defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
     return sysconf(_SC_PAGE_SIZE);
 #elif defined(ARCH_OS_WINDOWS)
     SYSTEM_INFO info;

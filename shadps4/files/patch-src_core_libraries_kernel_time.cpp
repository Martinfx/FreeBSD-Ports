--- src/core/libraries/kernel/time.cpp.orig	2025-03-22 22:14:04 UTC
+++ src/core/libraries/kernel/time.cpp
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: GPL-2.0-or-later
 
 #include <thread>
+#include <chrono>
 
 #include "common/assert.h"
 #include "common/native_clock.h"
@@ -17,7 +18,7 @@
 #include "common/ntapi.h"
 
 #else
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
 #include <date/tz.h>
 #endif
 #include <sys/resource.h>
@@ -422,7 +423,7 @@ int PS4_SYSV_ABI sceKernelConvertUtcToLocaltime(time_t
     // std::chrono::current_zone() not available yet.
     const auto* time_zone = date::current_zone();
 #else
-    const auto* time_zone = std::chrono::current_zone();
+    const auto* time_zone = date::current_zone();
 #endif
     auto info = time_zone->get_info(std::chrono::system_clock::now());
 
@@ -470,4 +471,4 @@ void RegisterTime(Core::Loader::SymbolsResolver* sym) 
     LIB_FUNCTION("-o5uEDpN+oY", "libkernel", 1, "libkernel", 1, 1, sceKernelConvertUtcToLocaltime);
 }
 
-} // namespace Libraries::Kernel
\ No newline at end of file
+} // namespace Libraries::Kernel

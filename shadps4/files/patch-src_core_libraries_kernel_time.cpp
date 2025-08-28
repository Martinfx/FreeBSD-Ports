--- src/core/libraries/kernel/time.cpp.orig	2025-07-06 18:24:57 UTC
+++ src/core/libraries/kernel/time.cpp
@@ -2,6 +2,7 @@
 // SPDX-License-Identifier: GPL-2.0-or-later
 
 #include <thread>
+#include <chrono>
 
 #include "common/assert.h"
 #include "common/native_clock.h"
@@ -16,7 +17,7 @@
 #include <windows.h>
 #include "common/ntapi.h"
 #else
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
 #include <date/tz.h>
 #endif
 #include <ctime>
@@ -489,7 +490,7 @@ s32 PS4_SYSV_ABI sceKernelConvertUtcToLocaltime(time_t
     // std::chrono::current_zone() not available yet.
     const auto* time_zone = date::current_zone();
 #else
-    const auto* time_zone = std::chrono::current_zone();
+    const auto* time_zone = date::current_zone();
 #endif
     auto info = time_zone->get_info(std::chrono::system_clock::now());
 
@@ -544,4 +545,4 @@ void RegisterTime(Core::Loader::SymbolsResolver* sym) 
     LIB_FUNCTION("-o5uEDpN+oY", "libkernel", 1, "libkernel", 1, 1, sceKernelConvertUtcToLocaltime);
 }
 
-} // namespace Libraries::Kernel
\ No newline at end of file
+} // namespace Libraries::Kernel

--- src/common/debug.h.orig	2025-08-28 03:34:26 UTC
+++ src/common/debug.h
@@ -11,7 +11,7 @@
 #error What the fuck is this compiler
 #endif
 
-#include <tracy/Tracy.hpp>
+#include <tracy/tracy/Tracy.hpp>
 
 static inline bool IsProfilerConnected() {
 #if TRACY_ENABLE

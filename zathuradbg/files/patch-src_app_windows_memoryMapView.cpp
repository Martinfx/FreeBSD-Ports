--- src/app/windows/memoryMapView.cpp.orig	2025-07-28 10:59:51 UTC
+++ src/app/windows/memoryMapView.cpp
@@ -1,4 +1,5 @@
 #include "windows.hpp"
+#include <icicle.h>
 
 std::vector<MemRegionInfo> getMemoryMapping(Icicle* ic)
 {

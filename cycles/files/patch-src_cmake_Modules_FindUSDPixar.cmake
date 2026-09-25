--- src/cmake/Modules/FindUSDPixar.cmake.orig	2025-10-18 14:00:18 UTC
+++ src/cmake/Modules/FindUSDPixar.cmake
@@ -14,6 +14,11 @@ if(pxr_FOUND)
   # USD
   set(USD_INCLUDE_DIRS ${PXR_INCLUDE_DIRS})
   set(USD_LIBRARIES hd hgi hgiGL usd usdImaging usdGeom)
+  # In a monolithic USD build these are interface targets only, and the
+  # library itself is usd_m.
+  if(TARGET usd_m)
+    list(APPEND USD_LIBRARIES usd_m)
+  endif()
 
   # OpenSubdiv
   find_library(_opensubdiv_library_cpu_debug_pxr NAMES osdCPU_d osdCPU PATHS ${_pxr_library_dir} NO_DEFAULT_PATH)

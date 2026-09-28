--- build_files/cmake/macros.cmake.orig	2026-09-28 10:00:00 UTC
+++ build_files/cmake/macros.cmake
@@ -598,10 +598,14 @@ endfunction()
 function(get_compiler_simd_flags
   _simd_flags)
 
-  if(CMAKE_SYSTEM_PROCESSOR MATCHES "(x86_64)|(AMD64)" OR CMAKE_OSX_ARCHITECTURES MATCHES x86_64)
+  if(CMAKE_SYSTEM_PROCESSOR MATCHES "(x86_64)|(AMD64)|(amd64)" OR CMAKE_OSX_ARCHITECTURES MATCHES x86_64)
     # message(STATUS "Detecting SIMD support")
     if((CMAKE_C_COMPILER_ID STREQUAL "GNU") OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
-      set(${_simd_flags} "-march=x86-64-v2" PARENT_SCOPE)
+      if(BLENDER_X86_MARCH)
+        set(${_simd_flags} "-march=${BLENDER_X86_MARCH}" PARENT_SCOPE)
+      else()
+        set(${_simd_flags} "-march=x86-64-v2" PARENT_SCOPE)
+      endif()
     elseif(MSVC)
       # MSVC has no specific compile flags for SSE42 (only for AVX).
       set(${_simd_flags} PARENT_SCOPE)

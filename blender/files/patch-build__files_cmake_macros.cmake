--- build_files/cmake/macros.cmake.orig	2026-09-26 12:00:00 UTC
+++ build_files/cmake/macros.cmake
@@ -548,7 +548,11 @@ macro(TEST_SSE_SUPPORT
 
   # message(STATUS "Detecting SSE support")
   if(CMAKE_COMPILER_IS_GNUCC OR (CMAKE_C_COMPILER_ID MATCHES "Clang"))
-    set(${_sse42_flags} "-march=x86-64-v2")
+    if(BLENDER_X86_MARCH)
+      set(${_sse42_flags} "-march=${BLENDER_X86_MARCH}")
+    else()
+      set(${_sse42_flags} "-march=x86-64-v2")
+    endif()
   elseif(MSVC)
     # MSVC has no specific build flags for SSE42, but when using intrinsics it will
     # generate the right instructions.

--- halide.cmake.orig	2019-11-29 00:39:21 UTC
+++ halide.cmake
@@ -143,6 +143,7 @@ function(halide_library_from_generator BASENAME)
        "${FEATURE}" STREQUAL "linux" OR
        "${FEATURE}" STREQUAL "osx" OR
        "${FEATURE}" STREQUAL "windows" OR
+       "${FEATURE}" STREQUAL "freebsd" OR
        "${FEATURE}" STREQUAL "ios" OR
        "${FEATURE}" STREQUAL "android")
       message(FATAL_ERROR "HALIDE_TARGET_FEATURES may not the Arch/OS/Bits string '${FEATURE}'; use HALIDE_TARGET instead.")

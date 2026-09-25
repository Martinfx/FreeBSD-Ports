--- cmake/defaults/Packages.cmake.orig	2026-02-23 22:54:59 UTC
+++ cmake/defaults/Packages.cmake
@@ -253,7 +253,8 @@ if (PXR_BUILD_IMAGING)
         add_definitions(-DPXR_OPENVDB_SUPPORT_ENABLED)
     endif()
     # --X11
-    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
+    if (CMAKE_SYSTEM_NAME STREQUAL "Linux" OR
+        CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
         find_package(X11)
         add_definitions(-DPXR_X11_SUPPORT_ENABLED)
     endif()

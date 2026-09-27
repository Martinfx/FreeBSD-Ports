--- cmake/defaults/Packages.cmake.orig	2026-04-24 18:55:54 UTC
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
@@ -299,6 +300,11 @@ endif()
 
 if(PXR_ENABLE_OSL_SUPPORT)
     find_package(OSL REQUIRED)
+    # sdrOsl uses OpenImageIO types from the OSL API and links
+    # ${OIIO_LIBRARIES}, which are only found for PXR_BUILD_OPENIMAGEIO_PLUGIN.
+    if (NOT OIIO_LIBRARIES)
+        find_package(OpenImageIO REQUIRED)
+    endif()
     set(REQUIRES_Imath TRUE)
     add_definitions(-DPXR_OSL_SUPPORT_ENABLED)
 endif()

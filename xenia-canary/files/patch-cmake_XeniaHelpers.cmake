--- cmake/XeniaHelpers.cmake.orig
+++ cmake/XeniaHelpers.cmake
@@ -63,7 +63,7 @@ function(xe_platform_sources target base_path)
     file(${glob_mode} _plat_sources      "${base_path}/*_win.h"
       "${base_path}/*_win.cc"
     )
-  elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
+  elseif(CMAKE_SYSTEM_NAME MATCHES "Linux|FreeBSD")
     file(${glob_mode} _plat_sources      "${base_path}/*_posix.h"
       "${base_path}/*_posix.cc"
       "${base_path}/*_linux.h"

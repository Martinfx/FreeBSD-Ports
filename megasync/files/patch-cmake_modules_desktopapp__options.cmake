--- cmake/modules/desktopapp_options.cmake.orig	2026-03-02 15:41:13 UTC
+++ cmake/modules/desktopapp_options.cmake
@@ -39,5 +39,5 @@ endif()
     set(ENABLE_MEDIA_FILE_METADATA ON)
 endif()
 
-include(sdklib_options)
+#include(sdklib_options)
 

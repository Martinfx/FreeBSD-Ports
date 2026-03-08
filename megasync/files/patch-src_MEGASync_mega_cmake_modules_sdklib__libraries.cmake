--- src/MEGASync/mega/cmake/modules/sdklib_libraries.cmake.orig	2026-01-13 01:44:33 UTC
+++ src/MEGASync/mega/cmake/modules/sdklib_libraries.cmake
@@ -98,7 +98,8 @@ macro(load_sdklib_libraries)
 
         find_package(PkgConfig REQUIRED) # For libraries loaded using pkg-config
 
-        pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcrypto++)
+        pkg_check_modules(cryptopp REQUIRED)
+	pkg_check_modules(cryptopp REQUIRED IMPORTED_TARGET libcryptopp)
         target_link_libraries(SDKlib PUBLIC PkgConfig::cryptopp) # TODO: Private for SDK core
 
         pkg_check_modules(sodium REQUIRED IMPORTED_TARGET libsodium)
@@ -126,8 +127,24 @@ macro(load_sdklib_libraries)
 
         if(USE_FREEIMAGE)
             # FreeImage has no pkg-config file. Use out own FindFreeImage.cmake to find the library.
-            find_package(FreeImage REQUIRED)
-            target_link_libraries(SDKlib PRIVATE FreeImage::FreeImage)
+            #find_package(FreeImage REQUIRED)
+            find_path(FREEIMAGE_INCLUDE_DIR FreeImage.h
+          	PATHS /usr/local/include)
+
+
+			find_library(FREEIMAGE_LIBRARY NAMES freeimage
+             PATHS /usr/local/lib)
+
+			include(FindPackageHandleStandardArgs)
+			find_package_handle_standard_args(FreeImage
+    		REQUIRED_VARS FREEIMAGE_LIBRARY FREEIMAGE_INCLUDE_DIR)
+
+			if(FreeImage_FOUND)
+    			set(FreeImage_LIBRARIES ${FREEIMAGE_LIBRARY})
+    			set(reeImage_INCLUDE_DIRS ${FREEIMAGE_INCLUDE_DIR})
+			endif()
+
+			mark_as_advanced(FREEIMAGE_INCLUDE_DIR FREEIMAGE_LIBRARY)
         endif()
 
         if(USE_FFMPEG)

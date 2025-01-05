--- cmake/PlatformSpecific.cmake.orig	2025-01-05 18:42:48 UTC
+++ cmake/PlatformSpecific.cmake
@@ -273,10 +273,10 @@ endif()
 	set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3 -ftree-vectorize -funroll-loops -fvariable-expansion-in-unroller")
 endif()
 
-if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
+if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR ${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
 	set(CMAKE_EXE_LINKER_FLAGS -Wl,--disable-new-dtags,--version-script='${CMAKE_SOURCE_DIR}/cmake/exportmaps/linux_symbol_exports.map')
 	set(CMAKE_SHARED_LINKER_FLAGS -Wl,--disable-new-dtags,--version-script='${CMAKE_SOURCE_DIR}/cmake/exportmaps/linux_symbol_exports.map')
 	set(CMAKE_MODULE_LINKER_FLAGS -Wl,--disable-new-dtags,--version-script='${CMAKE_SOURCE_DIR}/cmake/exportmaps/linux_symbol_exports.map')
 	set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
-	set(CMAKE_INSTALL_RPATH "$ORIGIN")
+	set(CMAKE_INSTALL_RPATH "/usr/local/lib")
 endif()

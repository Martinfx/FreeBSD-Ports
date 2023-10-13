--- cmake/BuildMicroHttpd.cmake.orig	2023-09-22 06:15:26 UTC
+++ cmake/BuildMicroHttpd.cmake
@@ -14,8 +14,8 @@ ExternalProject_Add(libmicrohttpd
   SOURCE_DIR ${CMAKE_BINARY_DIR}/libmicrohttpd/
   CONFIGURE_COMMAND ${CMAKE_BINARY_DIR}/libmicrohttpd//configure --prefix=${CMAKE_BINARY_DIR}/libmicrohttpd/ --enable-shared --with-pic --libdir=${CMAKE_BINARY_DIR}/libmicrohttpd/lib/
   BINARY_DIR ${CMAKE_BINARY_DIR}/libmicrohttpd/
-  BUILD_COMMAND make
-  INSTALL_COMMAND make install
+  BUILD_COMMAND gmake
+  INSTALL_COMMAND gmake install
   LOG_DOWNLOAD 1
   LOG_UPDATE 1
   LOG_CONFIGURE 1

--- cmake/BuildRdkafka.cmake.orig	2023-03-27 10:51:49 UTC
+++ cmake/BuildRdkafka.cmake
@@ -13,8 +13,8 @@ ExternalProject_Add(librdkafka
   SOURCE_DIR ${CMAKE_BINARY_DIR}/librdkafka/
   BINARY_DIR ${CMAKE_BINARY_DIR}/librdkafka/
   CONFIGURE_COMMAND ${CMAKE_BINARY_DIR}/librdkafka/configure --prefix=${CMAKE_BINARY_DIR}/librdkafka/ --disable-zstd --disable-lz4-ext
-  BUILD_COMMAND make
-  INSTALL_COMMAND make install
+  BUILD_COMMAND gmake
+  INSTALL_COMMAND gmake install
   UPDATE_COMMAND ""
   LOG_DOWNLOAD 1
   LOG_UPDATE 1

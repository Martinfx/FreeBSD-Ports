--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/include/hdfspp/ioservice.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/include/hdfspp/ioservice.h
@@ -61,7 +61,7 @@
 #include <functional>
 #include <memory>
 
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 
 namespace hdfs {
 
@@ -130,7 +130,7 @@
    * Access underlying io_service object.  Only to be used in asio library calls.
    * After HDFS-11884 is complete only tests should need direct access to the asio::io_service.
    **/
-  virtual boost::asio::io_service& GetRaw() = 0;
+  virtual boost::asio::io_context& GetRaw() = 0;
 };
 
 

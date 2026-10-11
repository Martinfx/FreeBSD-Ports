--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/async_stream.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/async_stream.h
@@ -28,8 +28,8 @@
 namespace hdfs {
 
 // Contiguous buffer types
-typedef boost::asio::mutable_buffers_1 MutableBuffer;
-typedef boost::asio::const_buffers_1   ConstBuffer;
+typedef boost::asio::mutable_buffer MutableBuffer;
+typedef boost::asio::const_buffer   ConstBuffer;
 
 /*
  * asio-compatible stream implementation.

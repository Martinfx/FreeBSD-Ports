--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/reader/datatransfer_impl.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/reader/datatransfer_impl.h
@@ -104,8 +104,8 @@
   using ::hdfs::continuation::WriteDelimitedPBMessage;
 
   static const int kMagicNumber = htonl(kDataTransferSasl);
-  static const boost::asio::const_buffers_1 kMagicNumberBuffer = boost::asio::buffer(
-      reinterpret_cast<const char *>(kMagicNumber), sizeof(kMagicNumber));
+  static const boost::asio::const_buffer kMagicNumberBuffer = boost::asio::buffer(
+      reinterpret_cast<const char *>(&kMagicNumber), sizeof(kMagicNumber));
 
   struct State {
     DataTransferEncryptorMessageProto req0;

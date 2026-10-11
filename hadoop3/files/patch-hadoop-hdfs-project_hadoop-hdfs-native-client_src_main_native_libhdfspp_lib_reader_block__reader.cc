--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/reader/block_reader.cc.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/reader/block_reader.cc
@@ -285,14 +285,9 @@
 struct BlockReaderImpl::ReadData : continuation::Continuation
 {
   ReadData(BlockReaderImpl *parent, std::shared_ptr<size_t> bytes_transferred,
-        const boost::asio::mutable_buffers_1 &buf) : parent_(parent),
+        const boost::asio::mutable_buffer &buf) : parent_(parent),
                                                      bytes_transferred_(bytes_transferred), buf_(buf), shared_conn_(parent->dn_)
   {
-    buf_.begin();
-  }
-
-  ~ReadData() {
-    buf_.end();
   }
 
   virtual void Run(const Next &next) override {
@@ -332,7 +327,7 @@
 private:
   BlockReaderImpl *parent_;
   std::shared_ptr<size_t> bytes_transferred_;
-  const boost::asio::mutable_buffers_1 buf_;
+  const boost::asio::mutable_buffer buf_;
 
   // Keep DNConnection alive.
   std::shared_ptr<DataNodeConnection> shared_conn_;

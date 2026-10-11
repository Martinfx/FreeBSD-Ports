--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/connection/datanodeconnection.cc.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/connection/datanodeconnection.cc
@@ -35,7 +35,7 @@
 
   conn_.reset(new tcp::socket(io_service->GetRaw()));
   auto datanode_addr = dn_proto.id();
-  endpoints_[0] = tcp::endpoint(address::from_string(datanode_addr.ipaddr()),
+  endpoints_[0] = tcp::endpoint(make_address(datanode_addr.ipaddr()),
                                   datanode_addr.xferport());
   uuid_ = dn_proto.id().datanodeuuid();
 
@@ -73,7 +73,7 @@
 void DataNodeConnectionImpl::async_read_some(const MutableBuffer &buf,
              std::function<void (const boost::system::error_code & error, std::size_t bytes_transferred) > handler)
 {
-  event_handlers_->call("DN_read_req", "", "", buf.end() - buf.begin());
+  event_handlers_->call("DN_read_req", "", "", buf.size());
 
   mutex_guard state_lock(state_lock_);
   conn_->async_read_some(buf, handler);
@@ -82,7 +82,7 @@
 void DataNodeConnectionImpl::async_write_some(const ConstBuffer &buf,
              std::function<void (const boost::system::error_code & error, std::size_t bytes_transferred) > handler)
 {
-  event_handlers_->call("DN_write_req", "", "", buf.end() - buf.begin());
+  event_handlers_->call("DN_write_req", "", "", buf.size());
 
   mutex_guard state_lock(state_lock_);
   conn_->async_write_some(buf, handler);

--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/namenode_info.cc.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/namenode_info.cc
@@ -79,7 +79,6 @@
   std::shared_ptr<IoService> io_service_;
   std::string host_;
   std::string port_;
-  boost::asio::ip::tcp::resolver::query query_;
   boost::asio::ip::tcp::resolver resolver_;
   endpoint_vector endpoints_;
 
@@ -87,7 +86,7 @@
   std::shared_ptr<std::promise<Status>> result_status_;
  public:
   ScopedResolver(std::shared_ptr<IoService> service, const std::string &host, const std::string &port) :
-        io_service_(service), host_(host), port_(port), query_(host, port), resolver_(io_service_->GetRaw())
+        io_service_(service), host_(host), port_(port), resolver_(io_service_->GetRaw())
   {
     if(!io_service_)
       LOG_ERROR(kAsyncRuntime, << "ScopedResolver@" << this << " passed nullptr to io_service");
@@ -112,13 +111,14 @@
     std::shared_ptr<std::promise<Status>> shared_result = result_status_;
 
     // Callback to pull a copy of endpoints out of resolver and set promise
-    auto callback = [this, shared_result](const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::iterator out) {
+    auto callback = [this, shared_result](const boost::system::error_code &ec, boost::asio::ip::tcp::resolver::results_type results) {
       if(!ec) {
-        std::copy(out, boost::asio::ip::tcp::resolver::iterator(), std::back_inserter(endpoints_));
+        for (const auto &entry : results)
+          endpoints_.push_back(entry.endpoint());
       }
       shared_result->set_value( ToStatus(ec) );
     };
-    resolver_.async_resolve(query_, callback);
+    resolver_.async_resolve(host_, port_, callback);
     return true;
   }
 

--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/ioservice_impl.cc.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/ioservice_impl.cc
@@ -18,6 +18,9 @@
 
 #include "ioservice_impl.h"
 
+#include <boost/asio/executor_work_guard.hpp>
+#include <boost/asio/post.hpp>
+
 #include <thread>
 #include <mutex>
 #include <vector>
@@ -102,7 +105,7 @@
 }
 
 void IoServiceImpl::PostTask(std::function<void(void)> asyncTask) {
-  io_service_.post(asyncTask);
+  boost::asio::post(io_service_, asyncTask);
 }
 
 void IoServiceImpl::WorkerDeleter::operator()(std::thread *t) {
@@ -125,7 +128,7 @@
   // from escaping this library and crashing the process.
 
   // As recommended in http://www.boost.org/doc/libs/1_39_0/doc/html/boost_asio/reference/io_service.html#boost_asio.reference.io_service.effect_of_exceptions_thrown_from_handlers
-  boost::asio::io_service::work work(io_service_);
+  auto work = boost::asio::make_work_guard(io_service_);
   while(true)
   {
     try
@@ -145,7 +148,7 @@
   io_service_.stop();
 }
 
-boost::asio::io_service& IoServiceImpl::GetRaw() {
+boost::asio::io_context& IoServiceImpl::GetRaw() {
   return io_service_;
 }
 

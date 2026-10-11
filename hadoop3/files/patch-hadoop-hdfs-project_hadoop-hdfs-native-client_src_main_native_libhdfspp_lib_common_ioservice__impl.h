--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/ioservice_impl.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/lib/common/ioservice_impl.h
@@ -21,7 +21,7 @@
 
 #include "hdfspp/ioservice.h"
 
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 #include "common/new_delete.h"
 
 #include <mutex>
@@ -45,7 +45,7 @@
   void PostTask(std::function<void(void)> asyncTask) override;
   void Run() override;
   void Stop() override;
-  boost::asio::io_service& GetRaw() override;
+  boost::asio::io_context& GetRaw() override;
 
   // Add a single worker thread, in the common case try to avoid this in favor
   // of Init[Default]Workers. Public for use by tests and rare cases where a
@@ -57,7 +57,7 @@
 
  private:
   std::mutex state_lock_;
-  boost::asio::io_service io_service_;
+  boost::asio::io_context io_service_;
 
   // For doing logging + resource manager updates on thread start/exit
   void ThreadStartHook();

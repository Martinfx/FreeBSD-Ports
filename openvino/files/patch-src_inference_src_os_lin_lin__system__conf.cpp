--- src/inference/src/os/lin/lin_system_conf.cpp.orig	2026-10-17 22:20:00 UTC
+++ src/inference/src/os/lin/lin_system_conf.cpp
@@ -246,9 +246,8 @@
         std::map<int, int> sockets;
         int socketId = 0;
         _cores = 0;
-        while (!cpuinfo.eof()) {
-            std::string line;
-            std::getline(cpuinfo, line);
+        std::string line;
+        while (std::getline(cpuinfo, line)) {
             if (line.empty())
                 continue;
             auto delimeter = line.find(':');
@@ -265,6 +264,13 @@
             }
         }
         _processors = processors.size();
+#ifdef __FreeBSD__
+        // there is no /proc/cpuinfo: take the online processors, one core
+        // each, in one node
+        if (_processors == 0) {
+            _processors = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
+        }
+#endif
 
         _numa_nodes = sockets.size() == 0 ? 1 : sockets.size();
         _sockets = _numa_nodes;

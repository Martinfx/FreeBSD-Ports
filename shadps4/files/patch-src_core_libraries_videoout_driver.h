--- src/core/libraries/videoout/driver.h.orig	2025-04-08 06:00:59 UTC
+++ src/core/libraries/videoout/driver.h
@@ -10,6 +10,7 @@
 #include <condition_variable>
 #include <mutex>
 #include <queue>
+#include <thread>
 
 namespace Vulkan {
 struct Frame;

--- pxr/base/work/workTBB/detachedTask_impl.cpp.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/work/workTBB/detachedTask_impl.cpp
@@ -11,12 +11,34 @@
 
 #include <atomic>
 #include <chrono>
+#include <cstdlib>
 #include <thread>
 
 PXR_NAMESPACE_OPEN_SCOPE
 
 static std::atomic<std::thread *> detachedWaiter { nullptr };
 
+// The waiter thread keeps running while the process exits, and exit() calls
+// the destructors of the static objects of the libraries, where TBB frees its
+// global state: the waiter thread then crashed in dispatcher.Wait().  So stop
+// it at exit, before that (exit() calls the functions registered with
+// atexit() and these destructors in the reverse order of their registration),
+// and wait until it has returned from dispatcher.Wait(), but not for long:
+// the detached tasks it waits for might not finish at exit.
+static std::atomic<bool> detachedWaiterStop { false };
+static std::atomic<bool> detachedWaiterBusy { false };
+
+static void
+_StopDetachedWaiter()
+{
+    detachedWaiterStop = true;
+    const auto deadline =
+        std::chrono::steady_clock::now() + std::chrono::seconds(1);
+    while (detachedWaiterBusy && std::chrono::steady_clock::now() < deadline) {
+        std::this_thread::sleep_for(std::chrono::milliseconds(1));
+    }
+}
+
 WorkImpl_Dispatcher &
 WorkTBB_GetDetachedDispatcher()
 {
@@ -40,14 +62,19 @@ WorkTBB_EnsureDetachedTaskProgress()
             *newThread =
                 std::thread([&dispatcher]() {
                         while (true) {
-                            // Process detached tasks.
-                            dispatcher.Wait();
+                            detachedWaiterBusy = true;
+                            if (!detachedWaiterStop) {
+                                // Process detached tasks.
+                                dispatcher.Wait();
+                            }
+                            detachedWaiterBusy = false;
                             // Now sleep for a bit, and try again.
                             using namespace std::chrono_literals;
                             std::this_thread::sleep_for(50ms);
                         }
                     });
             newThread->detach();
+            std::atexit(_StopDetachedWaiter);
         }
         else {
             // We lost the race, so delete our temporary thread.

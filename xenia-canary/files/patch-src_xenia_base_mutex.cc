--- src/xenia/base/mutex.cc.orig
+++ src/xenia/base/mutex.cc
@@ -10,6 +10,10 @@
 #include "xenia/base/mutex.h"
 #if XE_PLATFORM_WIN32 == 1
 #include "xenia/base/platform_win.h"
+#elif XE_PLATFORM_FREEBSD == 1
+#include <pthread.h>
+#include <sys/types.h>
+#include <sys/umtx.h>
 #elif XE_PLATFORM_LINUX == 1
 #include <linux/futex.h>
 #include <pthread.h>
@@ -79,6 +83,15 @@ bool xe_fast_mutex::try_lock() {
 
 namespace {
 
+#if XE_PLATFORM_FREEBSD == 1
+inline int futex_wait(std::atomic<uint32_t>* addr, uint32_t expected) {
+  return _umtx_op(addr, UMTX_OP_WAIT_UINT_PRIVATE, expected, nullptr, nullptr);
+}
+
+inline int futex_wake(std::atomic<uint32_t>* addr, int count) {
+  return _umtx_op(addr, UMTX_OP_WAKE_PRIVATE, count, nullptr, nullptr);
+}
+#else
 inline int futex_wait(std::atomic<uint32_t>* addr, uint32_t expected) {
   return syscall(SYS_futex, addr, FUTEX_WAIT_PRIVATE, expected, nullptr,
                  nullptr, 0);
@@ -88,6 +101,7 @@ inline int futex_wake(std::atomic<uint32_t>* addr, int count) {
   return syscall(SYS_futex, addr, FUTEX_WAKE_PRIVATE, count, nullptr, nullptr,
                  0);
 }
+#endif
 
 // Only compared for equality, to detect the owner re-entering.
 inline uint64_t xe_current_thread_id() {

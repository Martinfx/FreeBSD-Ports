--- src/xenia/base/threading_posix.cc.orig
+++ src/xenia/base/threading_posix.cc
@@ -20,7 +20,10 @@
 #include <signal.h>
 #include <sys/resource.h>
 #include <sys/syscall.h>
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_FREEBSD
+#include <pthread_np.h>
+#include <sys/umtx.h>
+#elif XE_PLATFORM_LINUX
 #include <linux/futex.h>
 #endif
 #include <unistd.h>
@@ -47,6 +50,9 @@
 #if __GLIBC__ == 2 && __GLIBC_MINOR__ < 30
 #define gettid() syscall(SYS_gettid)
 #endif
+#if XE_PLATFORM_FREEBSD
+#define gettid() pthread_getthreadid_np()
+#endif
 #else
 #define XE_HAS_SIGEV_THREAD_ID 0
 #endif
@@ -144,7 +150,7 @@ void EnableAffinityConfiguration() {}
 // uint64_t ticks() { return mach_absolute_time(); }
 
 uint32_t current_thread_system_id() {
-  return static_cast<uint32_t>(syscall(SYS_gettid));
+  return static_cast<uint32_t>(gettid());
 }
 
 void MaybeYield() {
@@ -250,7 +256,9 @@ void NotifyMultiObjectWaiters() {
     return;
   }
   multi_wait_epoch.fetch_add(1, std::memory_order_seq_cst);
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_FREEBSD
+  _umtx_op(&multi_wait_epoch, UMTX_OP_WAKE_PRIVATE, INT_MAX, nullptr, nullptr);
+#elif XE_PLATFORM_LINUX
   syscall(SYS_futex, reinterpret_cast<uint32_t*>(&multi_wait_epoch),
           FUTEX_WAKE_PRIVATE, INT_MAX, nullptr, nullptr, 0);
 #endif
@@ -263,8 +271,14 @@ void WaitForMultiObjectSignal(uint32_t expected,
   timespec ts{};
   ts.tv_sec = static_cast<time_t>(timeout.count() / 1000);
   ts.tv_nsec = static_cast<long>((timeout.count() % 1000) * 1000000);
+#if XE_PLATFORM_FREEBSD
+  // A relative timeout is passed as a bare timespec, its size in uaddr.
+  _umtx_op(&multi_wait_epoch, UMTX_OP_WAIT_UINT_PRIVATE, expected,
+           reinterpret_cast<void*>(sizeof(ts)), &ts);
+#else
   syscall(SYS_futex, reinterpret_cast<uint32_t*>(&multi_wait_epoch),
           FUTEX_WAIT_PRIVATE, expected, &ts, nullptr, 0);
+#endif
 #else
   if (multi_wait_epoch.load(std::memory_order_seq_cst) == expected) {
     std::this_thread::sleep_for(
@@ -718,7 +732,7 @@ class PosixCondition<Thread> final : public PosixConditionBase {
   /// Thread::GetCurrentThread() on the main thread
   explicit PosixCondition(pthread_t thread)
       : thread_(thread),
-        tid_(static_cast<pid_t>(syscall(SYS_gettid))),
+        tid_(static_cast<pid_t>(gettid())),
         signaled_(false),
         exit_code_(0),
         state_(State::kRunning),
@@ -803,7 +817,14 @@ class PosixCondition<Thread> final : public PosixConditionBase {
   }
 #endif
 
+#if XE_PLATFORM_FREEBSD
+  // pthread_t is a pointer on FreeBSD.
+  uint32_t system_id() const {
+    return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(thread_));
+  }
+#else
   uint32_t system_id() const { return static_cast<uint32_t>(thread_); }
+#endif
 
   uint64_t affinity_mask() const {
     WaitStarted();
@@ -1404,7 +1425,7 @@ void* PosixCondition<Thread>::ThreadStartRoutine(void* parameter) {
   delete start_data;
 
   current_thread_ = thread;
-  thread->handle_.tid_ = static_cast<pid_t>(syscall(SYS_gettid));
+  thread->handle_.tid_ = static_cast<pid_t>(gettid());
   {
     std::unique_lock lock(thread->handle_.state_mutex_);
     thread->handle_.state_ =

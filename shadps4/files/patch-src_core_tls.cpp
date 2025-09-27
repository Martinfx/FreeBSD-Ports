--- src/core/tls.cpp.orig	2025-09-27 09:27:17 UTC
+++ src/core/tls.cpp
@@ -160,14 +160,28 @@ void SetTcbBase(void* image_address) {
 // Other POSIX x86_64
 
 void SetTcbBase(void* image_address) {
+#if defined(__linux__) && defined(__x86_64__)
     const int ret = syscall(SYS_arch_prctl, ARCH_SET_GS, (unsigned long)image_address);
     ASSERT_MSG(ret == 0, "Failed to set GS base: errno {}", errno);
+#elif defined(__FreeBSD__) && defined(__amd64__)
+    int ret = amd64_set_gsbase(image_address);
+    ASSERT_MSG(ret == 0, "Failed to set GS base (FreeBSD): errno {}", errno);
+#else
+#  error "SetTcbBase: unsupported platform"
+#endif
 }
 
 Tcb* GetTcbBase() {
     void* tcb = nullptr;
+#if defined(__linux__) && defined(__x86_64__)
     const int ret = syscall(SYS_arch_prctl, ARCH_GET_GS, &tcb);
     ASSERT_MSG(ret == 0, "Failed to get GS base: errno {}", errno);
+#elif defined(__FreeBSD__) && defined(__amd64__)
+    int ret = amd64_get_gsbase(&tcb);
+    ASSERT_MSG(ret == 0, "Failed to get GS base (FreeBSD): errno {}", errno);
+#else
+#  error "GetTcbBase: unsupported platform"
+#endif
     return static_cast<Tcb*>(tcb);
 }
 

--- vita3k/mem/src/mem.cpp.orig	2026-10-06 04:21:17 UTC
+++ vita3k/mem/src/mem.cpp
@@ -88,7 +88,7 @@ bool init(MemState &state, const bool us
     // http://man7.org/linux/man-pages/man2/mmap.2.html
     const int prot = PROT_NONE;
     const int flags = MAP_PRIVATE | MAP_ANONYMOUS;
-    const int fd = 0;
+    const int fd = -1; // MAP_ANONYMOUS requires fd == -1 on FreeBSD
     const off_t offset = 0;
     // preferred_address is only a hint for mmap, if it can't use it, the kernel will choose itself the address
     state.memory = Memory(static_cast<uint8_t *>(mmap(preferred_address, TOTAL_MEM_SIZE, prot, flags, fd, offset)), delete_memory);
@@ -621,6 +621,9 @@ static void signal_handler(int sig, sigi
 #else
 #ifdef __APPLE__
     const uint64_t err = context->uc_mcontext->__es.__err;
+#elif defined(__FreeBSD__)
+    // page fault error code pushed by the CPU (bit 1: write, bit 4: instruction fetch)
+    const uint64_t err = context->uc_mcontext.mc_err;
 #else
     const uint64_t err = context->uc_mcontext.gregs[REG_ERR];
 #endif
@@ -648,7 +651,7 @@ static void register_access_violation_ha
     if (sigaction(SIGSEGV, &sa, NULL) == -1) {
         LOG_CRITICAL("Failed to register an exception handler");
     }
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     // When accessing memory region which is PROT_NONE on macOS, it is raising SIGBUS not SIGSEGV.
     // So apply same signal handler to SIGBUS
     if (sigaction(SIGBUS, &sa, NULL) == -1) {

--- vita3k/mem/src/mem.cpp.orig	2025-04-27 08:26:36 UTC
+++ vita3k/mem/src/mem.cpp
@@ -621,6 +621,9 @@ static void signal_handler(int sig, siginfo_t *info, v
 #else
 #ifdef __APPLE__
     const uint64_t err = context->uc_mcontext->__es.__err;
+#elif defined(__FreeBSD__)
+    // FreeBSD standart uc_mcontext not has REG_ERR
+    const uint64_t err = 0;
 #else
     const uint64_t err = context->uc_mcontext.gregs[REG_ERR];
 #endif

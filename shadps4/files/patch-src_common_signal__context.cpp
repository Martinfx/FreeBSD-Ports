--- src/common/signal_context.cpp.orig	2025-03-22 22:14:04 UTC
+++ src/common/signal_context.cpp
@@ -7,6 +7,9 @@
 
 #ifdef _WIN32
 #include <windows.h>
+#elif defined(__FreeBSD__)
+#include <ucontext.h>
+#include <machine/ucontext.h>
 #else
 #include <sys/ucontext.h>
 #endif
@@ -22,6 +25,10 @@ void* GetXmmPointer(void* ctx, u8 index) {
 #define CASE(index)                                                                                \
     case index:                                                                                    \
         return (void*)(&((ucontext_t*)ctx)->uc_mcontext->__fs.__fpu_xmm##index);
+#elif defined(__FreeBSD__)
+#define CASE(index) \
+    case index: \
+        return (void*)(&((ucontext_t*)ctx)->uc_mcontext.mc_fpstate[index]);
 #else
 #define CASE(index)                                                                                \
     case index:                                                                                    \
@@ -57,6 +64,8 @@ void* GetRip(void* ctx) {
     return (void*)((EXCEPTION_POINTERS*)ctx)->ContextRecord->Rip;
 #elif defined(__APPLE__)
     return (void*)((ucontext_t*)ctx)->uc_mcontext->__ss.__rip;
+#elif defined(__FreeBSD__)
+    return (void*)((ucontext_t*)ctx)->uc_mcontext.mc_rip;
 #else
     return (void*)((ucontext_t*)ctx)->uc_mcontext.gregs[REG_RIP];
 #endif
@@ -67,6 +76,8 @@ void IncrementRip(void* ctx, u64 length) {
     ((EXCEPTION_POINTERS*)ctx)->ContextRecord->Rip += length;
 #elif defined(__APPLE__)
     ((ucontext_t*)ctx)->uc_mcontext->__ss.__rip += length;
+#elif defined(__FreeBSD__)
+    ((ucontext_t*)ctx)->uc_mcontext.mc_rip += length;
 #else
     ((ucontext_t*)ctx)->uc_mcontext.gregs[REG_RIP] += length;
 #endif
@@ -80,6 +91,10 @@ bool IsWriteError(void* ctx) {
     return ((ucontext_t*)ctx)->uc_mcontext->__es.__err & 0x2;
 #elif defined(ARCH_ARM64)
     return ((ucontext_t*)ctx)->uc_mcontext->__es.__esr & 0x40;
+#endif
+#elif defined(__FreeBSD__)
+#if defined(ARCH_X86_64)
+    return ((ucontext_t*)ctx)->uc_mcontext.mc_err & 0x2;
 #endif
 #else
 #if defined(ARCH_X86_64)
@@ -89,4 +104,4 @@ bool IsWriteError(void* ctx) {
 #endif
 #endif
 }
-} // namespace Common
\ No newline at end of file
+} // namespace Common

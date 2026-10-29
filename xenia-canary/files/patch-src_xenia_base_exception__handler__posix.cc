--- src/xenia/base/exception_handler_posix.cc.orig
+++ src/xenia/base/exception_handler_posix.cc
@@ -18,11 +18,98 @@
 #include "xenia/base/math.h"
 #include "xenia/base/platform.h"
 
+#if XE_PLATFORM_FREEBSD && XE_ARCH_AMD64
+#include <machine/fpu.h>
+#include <ucontext.h>
+#endif
+
 namespace xe {
 
+#if XE_PLATFORM_FREEBSD && XE_ARCH_AMD64
+// FreeBSD's mcontext_t has named registers instead of the gregs array of
+// glibc, map the REG_ indices used below to them.
+typedef __register_t greg_t;
+enum {
+  REG_RAX,
+  REG_RCX,
+  REG_RDX,
+  REG_RBX,
+  REG_RSP,
+  REG_RBP,
+  REG_RSI,
+  REG_RDI,
+  REG_R8,
+  REG_R9,
+  REG_R10,
+  REG_R11,
+  REG_R12,
+  REG_R13,
+  REG_R14,
+  REG_R15,
+  REG_RIP,
+  REG_EFL,
+  REG_ERR,
+};
+
+static greg_t& McontextGreg(mcontext_t& mcontext, size_t reg) {
+  switch (reg) {
+    case REG_RAX:
+      return mcontext.mc_rax;
+    case REG_RCX:
+      return mcontext.mc_rcx;
+    case REG_RDX:
+      return mcontext.mc_rdx;
+    case REG_RBX:
+      return mcontext.mc_rbx;
+    case REG_RSP:
+      return mcontext.mc_rsp;
+    case REG_RBP:
+      return mcontext.mc_rbp;
+    case REG_RSI:
+      return mcontext.mc_rsi;
+    case REG_RDI:
+      return mcontext.mc_rdi;
+    case REG_R8:
+      return mcontext.mc_r8;
+    case REG_R9:
+      return mcontext.mc_r9;
+    case REG_R10:
+      return mcontext.mc_r10;
+    case REG_R11:
+      return mcontext.mc_r11;
+    case REG_R12:
+      return mcontext.mc_r12;
+    case REG_R13:
+      return mcontext.mc_r13;
+    case REG_R14:
+      return mcontext.mc_r14;
+    case REG_R15:
+      return mcontext.mc_r15;
+    case REG_RIP:
+      return mcontext.mc_rip;
+    case REG_EFL:
+      return mcontext.mc_rflags;
+    default:
+      // The page fault error code, like REG_ERR on Linux.
+      return mcontext.mc_err;
+  }
+}
+#define XE_MCONTEXT_GREG(mcontext, reg) McontextGreg(mcontext, reg)
+// mc_fpstate holds the FXSAVE area on amd64.
+#define XE_MCONTEXT_XMM(mcontext) \
+  (reinterpret_cast<struct savefpu*>((mcontext).mc_fpstate)->sv_xmm)
+#else
+#define XE_MCONTEXT_GREG(mcontext, reg) ((mcontext).gregs[reg])
+#define XE_MCONTEXT_XMM(mcontext) ((mcontext).fpregs->_xmm)
+#endif
+
 bool signal_handlers_installed_ = false;
 struct sigaction original_sigill_handler_;
 struct sigaction original_sigsegv_handler_;
+#if XE_PLATFORM_FREEBSD
+// Some protection faults are reported as SIGBUS on FreeBSD.
+struct sigaction original_sigbus_handler_;
+#endif
 
 // This can be as large as needed, but isn't often needed.
 // As we will be sometimes firing many exceptions we want to avoid having to
@@ -41,27 +128,27 @@ static void ExceptionHandlerCallback(int signal_number, siginfo_t* signal_info,
   HostThreadContext thread_context;
 
 #if XE_ARCH_AMD64
-  thread_context.rip = uint64_t(mcontext.gregs[REG_RIP]);
-  thread_context.eflags = uint32_t(mcontext.gregs[REG_EFL]);
+  thread_context.rip = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RIP));
+  thread_context.eflags = uint32_t(XE_MCONTEXT_GREG(mcontext, REG_EFL));
   // The REG_ order may be different than the register indices in the
   // instruction encoding.
-  thread_context.rax = uint64_t(mcontext.gregs[REG_RAX]);
-  thread_context.rcx = uint64_t(mcontext.gregs[REG_RCX]);
-  thread_context.rdx = uint64_t(mcontext.gregs[REG_RDX]);
-  thread_context.rbx = uint64_t(mcontext.gregs[REG_RBX]);
-  thread_context.rsp = uint64_t(mcontext.gregs[REG_RSP]);
-  thread_context.rbp = uint64_t(mcontext.gregs[REG_RBP]);
-  thread_context.rsi = uint64_t(mcontext.gregs[REG_RSI]);
-  thread_context.rdi = uint64_t(mcontext.gregs[REG_RDI]);
-  thread_context.r8 = uint64_t(mcontext.gregs[REG_R8]);
-  thread_context.r9 = uint64_t(mcontext.gregs[REG_R9]);
-  thread_context.r10 = uint64_t(mcontext.gregs[REG_R10]);
-  thread_context.r11 = uint64_t(mcontext.gregs[REG_R11]);
-  thread_context.r12 = uint64_t(mcontext.gregs[REG_R12]);
-  thread_context.r13 = uint64_t(mcontext.gregs[REG_R13]);
-  thread_context.r14 = uint64_t(mcontext.gregs[REG_R14]);
-  thread_context.r15 = uint64_t(mcontext.gregs[REG_R15]);
-  std::memcpy(thread_context.xmm_registers, mcontext.fpregs->_xmm,
+  thread_context.rax = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RAX));
+  thread_context.rcx = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RCX));
+  thread_context.rdx = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RDX));
+  thread_context.rbx = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RBX));
+  thread_context.rsp = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RSP));
+  thread_context.rbp = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RBP));
+  thread_context.rsi = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RSI));
+  thread_context.rdi = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_RDI));
+  thread_context.r8 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R8));
+  thread_context.r9 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R9));
+  thread_context.r10 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R10));
+  thread_context.r11 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R11));
+  thread_context.r12 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R12));
+  thread_context.r13 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R13));
+  thread_context.r14 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R14));
+  thread_context.r15 = uint64_t(XE_MCONTEXT_GREG(mcontext, REG_R15));
+  std::memcpy(thread_context.xmm_registers, XE_MCONTEXT_XMM(mcontext),
               sizeof(thread_context.xmm_registers));
 #elif XE_ARCH_ARM64
   std::memcpy(thread_context.x, mcontext.regs, sizeof(thread_context.x));
@@ -103,13 +190,16 @@ static void ExceptionHandlerCallback(int signal_number, siginfo_t* signal_info,
     case SIGILL:
       ex.InitializeIllegalInstruction(&thread_context);
       break;
+#if XE_PLATFORM_FREEBSD
+    case SIGBUS:
+#endif
     case SIGSEGV: {
       Exception::AccessViolationOperation access_violation_operation;
 #if XE_ARCH_AMD64
       // x86_pf_error_code::X86_PF_WRITE
       constexpr uint64_t kX86PageFaultErrorCodeWrite = UINT64_C(1) << 1;
       access_violation_operation =
-          (uint64_t(mcontext.gregs[REG_ERR]) & kX86PageFaultErrorCodeWrite)
+          (uint64_t(XE_MCONTEXT_GREG(mcontext, REG_ERR)) & kX86PageFaultErrorCodeWrite)
               ? Exception::AccessViolationOperation::kWrite
               : Exception::AccessViolationOperation::kRead;
 #elif XE_ARCH_ARM64
@@ -163,8 +253,8 @@ static void ExceptionHandlerCallback(int signal_number, siginfo_t* signal_info,
     if (handlers_[i].first(&ex, handlers_[i].second)) {
       // Exception handled.
 #if XE_ARCH_AMD64
-      mcontext.gregs[REG_RIP] = greg_t(thread_context.rip);
-      mcontext.gregs[REG_EFL] = greg_t(thread_context.eflags);
+      XE_MCONTEXT_GREG(mcontext, REG_RIP) = greg_t(thread_context.rip);
+      XE_MCONTEXT_GREG(mcontext, REG_EFL) = greg_t(thread_context.eflags);
       uint32_t modified_register_index;
       // The order must match the order in X64Register.
       static constexpr size_t kIntRegisterMap[] = {
@@ -177,7 +267,7 @@ static void ExceptionHandlerCallback(int signal_number, siginfo_t* signal_info,
                                   &modified_register_index)) {
         modified_int_registers_remaining &=
             ~(UINT16_C(1) << modified_register_index);
-        mcontext.gregs[kIntRegisterMap[modified_register_index]] =
+        XE_MCONTEXT_GREG(mcontext, kIntRegisterMap[modified_register_index]) =
             thread_context.int_registers[modified_register_index];
       }
       uint16_t modified_xmm_registers_remaining = ex.modified_xmm_registers();
@@ -185,7 +275,7 @@ static void ExceptionHandlerCallback(int signal_number, siginfo_t* signal_info,
                                   &modified_register_index)) {
         modified_xmm_registers_remaining &=
             ~(UINT16_C(1) << modified_register_index);
-        std::memcpy(&mcontext.fpregs->_xmm[modified_register_index],
+        std::memcpy(&XE_MCONTEXT_XMM(mcontext)[modified_register_index],
                     &thread_context.xmm_registers[modified_register_index],
                     sizeof(vec128_t));
       }
@@ -237,6 +327,11 @@ void ExceptionHandler::Install(Handler fn, void* data) {
     if (sigaction(SIGSEGV, &signal_handler, &original_sigsegv_handler_) != 0) {
       assert_always("Failed to install new SIGSEGV handler");
     }
+#if XE_PLATFORM_FREEBSD
+    if (sigaction(SIGBUS, &signal_handler, &original_sigbus_handler_) != 0) {
+      assert_always("Failed to install new SIGBUS handler");
+    }
+#endif
     signal_handlers_installed_ = true;
   }
 
@@ -277,6 +372,11 @@ void ExceptionHandler::Uninstall(Handler fn, void* data) {
       if (sigaction(SIGSEGV, &original_sigsegv_handler_, NULL) != 0) {
         assert_always("Failed to restore original SIGSEGV handler");
       }
+#if XE_PLATFORM_FREEBSD
+      if (sigaction(SIGBUS, &original_sigbus_handler_, NULL) != 0) {
+        assert_always("Failed to restore original SIGBUS handler");
+      }
+#endif
       signal_handlers_installed_ = false;
     }
   }

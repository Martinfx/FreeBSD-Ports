--- src/core/libraries/kernel/threads/exception.cpp.orig	2025-07-06 18:24:57 UTC
+++ src/core/libraries/kernel/threads/exception.cpp
@@ -42,6 +42,25 @@ void SigactionHandler(int signum, siginfo_t* inf, ucon
         ctx.uc_mcontext.mc_rsp = regs.__rsp;
         ctx.uc_mcontext.mc_fs = regs.__fs;
         ctx.uc_mcontext.mc_gs = regs.__gs;
+#elif defined(__FreeBSD__)
+        ctx.uc_mcontext.mc_r8  = raw_context->uc_mcontext.mc_r8;
+        ctx.uc_mcontext.mc_r9  = raw_context->uc_mcontext.mc_r9;
+        ctx.uc_mcontext.mc_r10 = raw_context->uc_mcontext.mc_r10;
+        ctx.uc_mcontext.mc_r11 = raw_context->uc_mcontext.mc_r11;
+        ctx.uc_mcontext.mc_r12 = raw_context->uc_mcontext.mc_r12;
+        ctx.uc_mcontext.mc_r13 = raw_context->uc_mcontext.mc_r13;
+        ctx.uc_mcontext.mc_r14 = raw_context->uc_mcontext.mc_r14;
+        ctx.uc_mcontext.mc_r15 = raw_context->uc_mcontext.mc_r15;
+        ctx.uc_mcontext.mc_rdi = raw_context->uc_mcontext.mc_rdi;
+        ctx.uc_mcontext.mc_rsi = raw_context->uc_mcontext.mc_rsi;
+        ctx.uc_mcontext.mc_rbp = raw_context->uc_mcontext.mc_rbp;
+        ctx.uc_mcontext.mc_rbx = raw_context->uc_mcontext.mc_rbx;
+        ctx.uc_mcontext.mc_rdx = raw_context->uc_mcontext.mc_rdx;
+        ctx.uc_mcontext.mc_rax = raw_context->uc_mcontext.mc_rax;
+        ctx.uc_mcontext.mc_rcx = raw_context->uc_mcontext.mc_rcx;
+        ctx.uc_mcontext.mc_rsp = raw_context->uc_mcontext.mc_rsp;
+        ctx.uc_mcontext.mc_fs  = raw_context->uc_mcontext.mc_fs;
+        ctx.uc_mcontext.mc_gs  = raw_context->uc_mcontext.mc_gs;
 #else
         const auto& regs = raw_context->uc_mcontext.gregs;
         ctx.uc_mcontext.mc_r8 = regs[REG_R8];

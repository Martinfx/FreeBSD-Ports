--- src/common/signal_context.cpp.orig	2026-06-01 15:47:16 UTC
+++ src/common/signal_context.cpp
@@ -33,7 +33,7 @@
         auto& mctx = ((ucontext_t*)ctx)->uc_mcontext;                                              \
         ASSERT(mctx.mc_fpformat == _MC_FPFMT_XMM);                                                 \
         auto* s_fpu = (struct savefpu*)(&mctx.mc_fpstate[0]);                                      \
-        return (void*)(&(s_fpu->sv_xmm[0]));                                                       \
+        return (void*)(&(s_fpu->sv_xmm[index]));                                                   \
     }
 #else
 #define CASE(index)                                                                                \

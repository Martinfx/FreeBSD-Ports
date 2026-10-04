--- src/core/cpu_patches.cpp.orig	2026-10-02 12:00:00 UTC
+++ src/core/cpu_patches.cpp
@@ -715,7 +715,7 @@
         auto& mctx = ((ucontext_t*)ctx)->uc_mcontext;                                              \
         ASSERT(mctx.mc_fpformat == _MC_FPFMT_XMM);                                                 \
         auto* s_fpu = (struct savefpu*)(&mctx.mc_fpstate[0]);                                      \
-        return (void*)(&(s_fpu->sv_xmm[0]));                                                       \
+        return (void*)(&(s_fpu->sv_xmm[index]));                                                   \
     }
 #else
 #define CASE(index)                                                                                \

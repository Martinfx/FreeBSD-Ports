--- src/content/browser/zygote_host/zygote_host_impl_linux.h.orig	2026-10-18 18:43:23 UTC
+++ src/content/browser/zygote_host/zygote_host_impl_linux.h
@@ -50,12 +50,14 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
       base::ScopedFD* control_fd,
       base::FileHandleMappingVector additional_remapped_fds);
 
+#if !BUILDFLAG(IS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
 #if BUILDFLAG(IS_CHROMEOS)
   void ReinitializeLogging(uint32_t logging_dest,
                            base::PlatformFile log_file_fd) override;
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
   bool HasZygote() { return has_zygote_; }
 
@@ -76,9 +78,11 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
   // other threads are created.
   bool has_zygote_ = false;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.

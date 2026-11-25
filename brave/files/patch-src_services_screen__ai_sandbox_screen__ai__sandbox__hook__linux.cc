--- src/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc.orig	2026-11-24 12:50:30 UTC
+++ src/services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.cc
@@ -59,6 +59,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
     }
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
 
   std::vector<BrokerFilePermission> permissions{
@@ -80,6 +81,7 @@ bool ScreenAIPreSandboxHook(base::FilePa
                             sandbox::syscall_broker::COMMAND_OPEN}),
       permissions, options);
   instance->EngageNamespaceSandboxIfPossible();
+#endif
 
   return true;
 }

--- src/content/utility/utility_blink_platform_with_sandbox_support_impl.h.orig	2026-11-24 12:50:30 UTC
+++ src/content/utility/utility_blink_platform_with_sandbox_support_impl.h
@@ -38,7 +38,7 @@ class UtilityBlinkPlatformWithSandboxSup
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 };

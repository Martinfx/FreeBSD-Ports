--- src/chrome/enterprise_companion/event_logger.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/enterprise_companion/event_logger.cc
@@ -129,7 +129,7 @@ proto::EnterpriseCompanionMetadata GetMe
   metadata.set_application_arch(proto::ARM64);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metadata.set_os_platform(proto::LINUX);
 #elif BUILDFLAG(IS_MAC)
   metadata.set_os_platform(proto::MAC);

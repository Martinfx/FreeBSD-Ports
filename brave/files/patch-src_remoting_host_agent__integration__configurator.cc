--- src/remoting/host/agent_integration_configurator.cc.orig	2026-11-24 12:50:30 UTC
+++ src/remoting/host/agent_integration_configurator.cc
@@ -16,7 +16,7 @@ AgentIntegrationConfigurator::AgentInteg
 
 AgentIntegrationConfigurator::~AgentIntegrationConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 // static
 void AgentIntegrationConfigurator::IsSupported(IsSupportedCallback callback) {

--- src/extensions/browser/api/api_browser_context_keyed_service_factories.cc.orig	2026-11-24 12:50:30 UTC
+++ src/extensions/browser/api/api_browser_context_keyed_service_factories.cc
@@ -139,7 +139,7 @@ void EnsureApiBrowserContextKeyedService
   MediaPerceptionAPIManager::GetFactoryInstance();
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   NetworkingPrivateEventRouterFactory::GetInstance();
 #endif
   PrinterProviderAPIFactory::GetInstance();

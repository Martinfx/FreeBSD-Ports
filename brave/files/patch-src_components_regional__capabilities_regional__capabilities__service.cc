--- src/components/regional_capabilities/regional_capabilities_service.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/regional_capabilities/regional_capabilities_service.cc
@@ -460,7 +460,7 @@ bool RegionalCapabilitiesService::IsInAn
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInAnySearchEngineChoiceScreenRegion(
     Client& client) {

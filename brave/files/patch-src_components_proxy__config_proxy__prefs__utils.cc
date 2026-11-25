--- src/components/proxy_config/proxy_prefs_utils.cc.orig	2026-11-24 12:50:30 UTC
+++ src/components/proxy_config/proxy_prefs_utils.cc
@@ -65,7 +65,7 @@ bool ProxyOverrideRulesAllowed(const Pre
                                policy::PolicyService* policy_service) {
   CHECK(pref_service);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
       1) {
     return true;

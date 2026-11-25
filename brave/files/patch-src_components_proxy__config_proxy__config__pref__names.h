--- src/components/proxy_config/proxy_config_pref_names.h.orig	2026-11-24 12:50:30 UTC
+++ src/components/proxy_config/proxy_config_pref_names.h
@@ -20,7 +20,7 @@ inline constexpr char kUseSharedProxies[
 inline constexpr char kProxyOverrideRules[] = "proxy_override_rules";
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Preference to store the scope (user vs machine) corresponding to the value
 // set in `kProxyOverrideRules`. It is used to handle the policy differently
 // when its source is a cloud user depending on its affiliation status and the

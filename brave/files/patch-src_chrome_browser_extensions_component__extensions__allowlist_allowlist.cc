--- src/chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -61,7 +61,7 @@ bool IsComponentExtensionAllowlisted(con
       extension_misc::kQuickOfficeComponentExtensionId,
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)

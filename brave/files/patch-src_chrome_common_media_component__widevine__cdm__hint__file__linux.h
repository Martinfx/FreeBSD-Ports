--- src/chrome/common/media/component_widevine_cdm_hint_file_linux.h.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/common/media/component_widevine_cdm_hint_file_linux.h
@@ -14,7 +14,7 @@
 #error "This file only applies when Widevine used."
 #endif
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #error "This file only applies to desktop Linux and ChromeOS."
 #endif
 

--- src/components/password_manager/core/browser/password_form_filling.cc.orig	2026-11-02 23:22:33 UTC
+++ src/components/password_manager/core/browser/password_form_filling.cc
@@ -180,7 +180,7 @@ LikelyFormFilling SendFillInformationToR
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (!should_show_popup_without_passwords) {
       url::Origin origin =
           base::FeatureList::IsEnabled(

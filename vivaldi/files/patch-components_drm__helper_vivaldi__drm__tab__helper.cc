--- components/drm_helper/vivaldi_drm_tab_helper.cc.orig	2026-08-25 00:00:00 UTC
+++ components/drm_helper/vivaldi_drm_tab_helper.cc
@@ -10,7 +10,7 @@
 #include "extensions/api/autoupdate/autoupdate_api.h"
 #endif
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #include "app/vivaldi_resources.h"
 #include "chrome/browser/ui/browser.h"
 #include "components/infobars/content/content_infobar_manager.h"
@@ -20,7 +20,7 @@
 
 namespace drm_helper {
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 static constexpr char kWidevineComponentID[] =
     "oimompecagnajdejgnnjijobebaeigek";
 #endif
@@ -46,7 +46,7 @@ DRMContentTabHelper::DRMContentTabHelper
     : content::WebContentsObserver(web_contents),
       content::WebContentsUserData<DRMContentTabHelper>(*web_contents),
       media_access_receivers_{web_contents, this} {
-#if !BUILDFLAG(IS_LINUX) && !defined(VIVALDI_SPARKLE_DISABLED)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD) && !defined(VIVALDI_SPARKLE_DISABLED)
   auto* auto_update = extensions::AutoUpdateAPI::GetFactoryInstance()->Get(
       web_contents->GetBrowserContext());
 
@@ -65,7 +65,7 @@ DRMContentTabHelper::DRMContentTabHelper
 }
 
 void DRMContentTabHelper::OnEvent(const update_client::CrxUpdateItem& item) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // For non-linux platforms, we want to handle tab reloading here (CDM gets to
   // be used).
   if (item.id == kWidevineComponentID) {
@@ -78,7 +78,7 @@ void DRMContentTabHelper::OnEvent(const
 #endif
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 void DRMContentTabHelper::HandleModuleUpdated() {
   if (was_requested_) {
     infobars::ContentInfoBarManager* infobar_manager =
@@ -126,7 +126,7 @@ void DRMContentTabHelper::NotifyEncrypte
   if (auto_update->WasWidevineAvailable())
     return;
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // This will be used for tab reload later.
   was_requested_ = true;
 #endif

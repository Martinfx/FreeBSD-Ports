--- components/drm_helper/vivaldi_drm_tab_helper.h.orig	2026-08-25 00:00:00 UTC
+++ components/drm_helper/vivaldi_drm_tab_helper.h
@@ -7,7 +7,7 @@
 #include "content/public/browser/web_contents_user_data.h"
 #include "renderer/mojo/vivaldi_encrypted_media_access.mojom.h"
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #endif
 
@@ -39,7 +39,7 @@ class DRMContentTabHelper
       vivaldi::mojom::VivaldiEncryptedMediaAccess>
       media_access_receivers_;
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   void HandleModuleUpdated();
 
   base::ScopedObservation<component_updater::ComponentUpdateService,

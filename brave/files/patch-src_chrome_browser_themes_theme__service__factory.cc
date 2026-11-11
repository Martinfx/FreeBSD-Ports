--- src/chrome/browser/themes/theme_service_factory.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/themes/theme_service_factory.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
@@ -112,7 +112,7 @@ std::unique_ptr<KeyedService>
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
   BRAVE_THEMESERVICEFACTORY_BUILDSERVICEINSTANCEFOR
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #elif BUILDFLAG(IS_ANDROID)
   using ThemeService = ThemeServiceAndroid;

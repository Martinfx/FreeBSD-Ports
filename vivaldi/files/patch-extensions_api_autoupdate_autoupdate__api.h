--- extensions/api/autoupdate/autoupdate_api.h.orig	2026-08-25 00:00:00 UTC
+++ extensions/api/autoupdate/autoupdate_api.h
@@ -138,7 +138,7 @@ class AutoUpdateAPI : public BrowserCont
       observer_{this};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void InitUpgradeDetection();
   void ShutdownUpgradeDetection();
 

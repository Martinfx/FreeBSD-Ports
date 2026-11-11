--- src/chrome/browser/chrome_browser_main_linux.h.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/chrome_browser_main_linux.h
@@ -40,7 +40,7 @@ class ChromeBrowserMainPartsLinux : publ
   void PreCreateMainMessageLoop() override;
 #endif
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;

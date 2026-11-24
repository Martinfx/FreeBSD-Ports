--- src/chrome/browser/chrome_browser_main_posix.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/chrome_browser_main_posix.cc
@@ -91,7 +91,7 @@ void ExitHandler::ExitWhenPossibleOnUITh
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:

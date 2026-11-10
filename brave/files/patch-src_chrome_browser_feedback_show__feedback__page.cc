--- src/chrome/browser/feedback/show_feedback_page.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/feedback/show_feedback_page.cc
@@ -295,7 +295,7 @@ bool CanSubmitFeedback(const Profile* pr
     return false;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   // Incognito profiles should apply the same restrictions as their original
   // profile.

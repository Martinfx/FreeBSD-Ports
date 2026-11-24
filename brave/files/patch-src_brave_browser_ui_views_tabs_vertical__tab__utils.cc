--- src/brave/browser/ui/views/tabs/vertical_tab_utils.cc.orig	2026-11-24 12:50:30 UTC
+++ src/brave/browser/ui/views/tabs/vertical_tab_utils.cc
@@ -25,7 +25,8 @@ std::pair<int, int> GetLeadingTrailingCa
   // On Mac, frame_view->GetBrowserLayoutParams() gives more wider width than
   // we want.
   return {80, 0};
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+// The #else branch is a hard #error, so FreeBSD has to take the Linux path.
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* frame_view = frame->GetFrameView();
   if (!frame_view) {
     return {};

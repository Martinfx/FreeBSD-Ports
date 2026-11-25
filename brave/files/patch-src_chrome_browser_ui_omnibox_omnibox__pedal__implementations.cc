--- src/chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2028,7 +2028,7 @@ const gfx::VectorIcon& GetSharingHubVect
   return features::IsRoundedIconsEnabled()
              ? omnibox::kShareWindowsIcon
              : omnibox::kShareWinChromeRefreshOldIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return features::IsRoundedIconsEnabled()
              ? omnibox::kSendIcon
              : omnibox::kShareLinuxChromeRefreshOldIcon;

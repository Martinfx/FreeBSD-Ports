--- src/chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1973,7 +1973,7 @@ void LocationBarView::OnPopupStateChange
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the

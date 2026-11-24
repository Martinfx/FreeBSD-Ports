--- src/content/browser/web_contents/web_contents_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/content/browser/web_contents/web_contents_impl.cc
@@ -1462,7 +1462,7 @@ WebContentsImpl::WebContentsImpl(Browser
   renderer_preferences_.caret_blink_interval =
       native_theme->caret_blink_interval();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   renderer_preferences_.use_overlay_scrollbar =
       native_theme->use_overlay_scrollbar();
 #endif
@@ -12930,7 +12930,7 @@ void WebContentsImpl::OnNativeThemeUpdat
 
   const auto caret_blink_interval = observed_theme->caret_blink_interval();
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const auto use_overlay_scrollbar = observed_theme->use_overlay_scrollbar();
 #endif
   bool renderer_preference_changed = false;
@@ -12939,7 +12939,7 @@ void WebContentsImpl::OnNativeThemeUpdat
     renderer_preference_changed = true;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (renderer_preferences_.use_overlay_scrollbar != use_overlay_scrollbar) {
     renderer_preferences_.use_overlay_scrollbar = use_overlay_scrollbar;
     renderer_preference_changed = true;

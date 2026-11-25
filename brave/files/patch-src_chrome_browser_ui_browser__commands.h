--- src/chrome/browser/ui/browser_commands.h.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/ui/browser_commands.h
@@ -352,7 +352,7 @@ void ToggleShowSearchTools(BrowserWindow
 void ShowAppMenu(BrowserWindowInterface* browser);
 void ShowAvatarMenu(BrowserWindowInterface* browser);
 void MaybeUpdateChrome(BrowserWindowInterface* browser);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenScheduledRestartDialog(BrowserWindowInterface* browser);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 bool CanRequestTabletSite(content::WebContents* current_tab);

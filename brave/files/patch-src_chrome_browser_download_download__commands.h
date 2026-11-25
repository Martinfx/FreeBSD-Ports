--- src/chrome/browser/download/download_commands.h.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/browser/download/download_commands.h
@@ -72,7 +72,7 @@ class DownloadCommands {
   void ExecuteCommand(Command command);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool IsDownloadPdf() const;
   bool CanOpenPdfInSystemViewer() const;
   BrowserWindowInterface* GetBrowser() const;

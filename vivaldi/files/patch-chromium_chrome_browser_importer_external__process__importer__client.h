--- chromium/chrome/browser/importer/external_process_importer_client.h.orig	2026-08-25 00:00:00 UTC
+++ chromium/chrome/browser/importer/external_process_importer_client.h
@@ -37,7 +37,7 @@ struct ImportedSpeedDialEntry;
 struct ImportedTabEntry;
 // End Vivaldi
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 namespace os_crypt_async {
 class Encryptor;
 class OSCryptAsync;
@@ -217,7 +217,7 @@ class ExternalProcessImporterClient
   size_t total_tab_count_;
 
   // Vivaldi: Handles the decryptor on UI thread.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Retrieves an Encryptor for the source product on the UI thread and forwards
   // the decryption callback to the current task runner.
   void GetDecryptorOnUIThread(

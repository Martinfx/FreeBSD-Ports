--- chromium/chrome/browser/importer/external_process_importer_client.cc.orig	2026-08-25 00:00:00 UTC
+++ chromium/chrome/browser/importer/external_process_importer_client.cc
@@ -22,7 +22,7 @@
 
 #include "app/vivaldi_resources.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/async/browser/os_crypt_async.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -136,7 +136,7 @@ void ExternalProcessImporterClient::OnIm
   if (cancelled_)
     return;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (pending_password_decryption_) {
     DeferredImportFinished deferred_import;
     deferred_import.succeeded = succeeded;
@@ -164,7 +164,7 @@ void ExternalProcessImporterClient::OnIm
   if (cancelled_)
     return;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (import_item == user_data_importer::PASSWORDS &&
       pending_password_decryption_) {
     deferred_password_item_finished_ = true;

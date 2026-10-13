--- importer/vivaldi_external_process_importer_client.cc.orig	2026-08-25 00:00:00 UTC
+++ importer/vivaldi_external_process_importer_client.cc
@@ -30,7 +30,7 @@
 #include "importer/vivaldi_profile_import_process_messages.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/posix_key_provider.h"
 #endif  // IS_LINUX
@@ -134,7 +134,7 @@ std::string GetSourceKeyFromLocalState(c
 #endif  // IS_WIN
 
 // On linux we use async ui thread approach.
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 
 std::string GetSourceRawKey(const base::FilePath& profile_dir,
                             user_data_importer::ImporterType importer_type) {
@@ -299,7 +299,7 @@ void ExternalProcessImporterClient::OnRa
 
   raw_passwords_.insert(raw_passwords_.end(), group.begin(), group.end());
   if (raw_passwords_.size() == total_raw_passwords_count_) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     if (raw_passwords_.empty())
       return;
 
@@ -346,13 +346,13 @@ void ExternalProcessImporterClient::OnRa
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void ExternalProcessImporterClient::GetDecryptorOnUIThread(
     const std::string& product_name,
     base::OnceCallback<void(scoped_refptr<os_crypt_async::Encryptor>)>
         callback) {
   DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const base::CommandLine& command_line =
       *base::CommandLine::ForCurrentProcess();
   std::string password_store =
@@ -369,7 +369,7 @@ void ExternalProcessImporterClient::GetD
   std::vector<std::pair<os_crypt_async::OSCryptAsync::Precedence,
                         std::unique_ptr<os_crypt_async::KeyProvider>>>
       providers;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   providers.emplace_back(/*precedence=*/10u, std::move(freedesktop_provider));
   providers.emplace_back(/*precedence=*/5u, std::move(posix_provider));
 #elif BUILDFLAG(IS_MAC)

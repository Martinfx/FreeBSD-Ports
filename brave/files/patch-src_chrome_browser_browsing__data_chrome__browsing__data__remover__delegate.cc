--- src/chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -737,6 +737,7 @@ void ChromeBrowsingDataRemoverDelegate::
   if (remove_mask & constants::DATA_TYPE_PRIVATE_VERIFICATION_TOKENS) {
     if (base::FeatureList::IsEnabled(
             net::features::kEnablePrivateVerificationTokens)) {
+#if !BUILDFLAG(IS_BSD)
       if (auto* pvt_service =
               PrivateVerificationTokensServiceFactory::GetForProfile(
                   profile_)) {
@@ -753,6 +754,9 @@ void ChromeBrowsingDataRemoverDelegate::
               filter_builder->BuildStorageKeyFilter(), std::move(done_closure));
         }
       }
+#else
+      LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
     }
   }
 

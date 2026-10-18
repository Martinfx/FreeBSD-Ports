--- src/chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -53,7 +53,10 @@ void PrivateVerificationTokensURLLoaderT
       !pvt_service_) {
     return;
   }
-
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -88,6 +91,7 @@ void PrivateVerificationTokensURLLoaderT
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -104,7 +108,7 @@ void PrivateVerificationTokensURLLoaderT
       if (profile_ && redeemer_origin_) {
         pvt_service_->TrackerInsert(profile_.get(), *redeemer_origin_);
       }
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
     redeemer_origin_.reset();
@@ -121,7 +125,7 @@ void PrivateVerificationTokensURLLoaderT
       if (profile_ && redeemer_origin_) {
         pvt_service_->TrackerInsert(profile_.get(), *redeemer_origin_);
       }
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
     redeemer_origin_.reset();

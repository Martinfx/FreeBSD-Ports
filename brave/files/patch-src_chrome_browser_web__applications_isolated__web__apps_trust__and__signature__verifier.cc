--- src/chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc.orig	2026-11-02 23:22:33 UTC
+++ src/chrome/browser/web_applications/isolated_web_apps/trust_and_signature_verifier.cc
@@ -43,6 +43,8 @@ void CheckTrustAndSignatures(
         void(base::expected<
              std::optional<web_package::SignedWebBundleIntegrityBlock>,
              std::string>)> callback) {
+// XXX crubit
+#if 0
   RETURN_IF_ERROR(IsolatedWebAppTrustChecker::IsOperationAllowed(
                       *profile, web_bundle_id, location.dev_mode(), operation),
                   [&](const std::string& error) {
@@ -65,6 +67,7 @@ void CheckTrustAndSignatures(
             std::move(callback).Run(base::ok(std::nullopt));
           }},
       location.variant());
+#endif
 }
 
 void CheckTrustAndSignatures(

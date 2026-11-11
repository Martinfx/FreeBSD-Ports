--- src/brave/components/brave_wallet/browser/polkadot/polkadot_signed_transfer_task.cc.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_signed_transfer_task.cc
@@ -6,6 +6,7 @@
 #include "brave/components/brave_wallet/browser/polkadot/polkadot_signed_transfer_task.h"
 
 #include "base/containers/to_vector.h"
+#include "base/strings/string_number_conversions.h"
 #include "brave/components/brave_wallet/browser/brave_wallet_utils.h"
 #include "brave/components/brave_wallet/browser/keyring_service.h"
 #include "brave/components/brave_wallet/browser/polkadot/polkadot_substrate_rpc.h"
@@ -254,18 +255,19 @@ void PolkadotSignedTransferTask::MaybeFi
                 signing_header_->block_number, *genesis_hash_,
                 *signing_block_hash_);
 
-  if (!signature_payload_result.has_value()) {
+  if (!signature_payload_result->is_ok()) {
     return StopWithError(WalletInternalErrorMessage());
   }
 
-  signature_payload_ = base::ToVector(*signature_payload_result);
+  auto signature_payload = signature_payload_result->unwrap();
+  signature_payload_ = base::ToVector(signature_payload->bytes);
 
   std::array<uint8_t, kSr25519SignatureSize> signature = {};
   if (use_dummy_signature_) {
     signature.fill(uint8_t{0x01});
   } else {
     auto sig = keyring_service_->SignMessageByPolkadotKeyring(
-        sender_account_id_, signature_payload_);
+        sender_account_id_, signature_payload->bytes);
     if (!sig) {
       return StopWithError(WalletInternalErrorMessage());
     }
@@ -288,10 +290,11 @@ void PolkadotSignedTransferTask::MaybeFi
                                   signature, signing_header_->block_number,
                                   account_info_->nonce);
 
-  if (!extrinsic_result.has_value()) {
+  if (!extrinsic_result->is_ok()) {
     return StopWithError(WalletInternalErrorMessage());
   }
-  extrinsic_ = base::ToVector(*extrinsic_result);
+  auto extrinsic = extrinsic_result->unwrap();
+  extrinsic_ = base::ToVector(extrinsic->bytes);
 
   std::move(callback_).Run(base::ok(GetMetadata()));
 }

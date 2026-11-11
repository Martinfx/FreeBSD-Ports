--- src/brave/components/brave_wallet/browser/polkadot/polkadot_transaction_status_task.cc.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_transaction_status_task.cc
@@ -239,7 +239,8 @@ void PolkadotTransactionStatusTask::OnGe
   std::array<uint8_t, 16> fee_bytes = {};
 
   bool was_successful = was_extrinsic_successful(
-      events.value(), *extrinsic_idx_, *pubkey, **chain_metadata_, fee_bytes);
+      ::rust::Slice<const uint8_t>(events.value()), *extrinsic_idx_, *pubkey,
+      **chain_metadata_, fee_bytes);
 
   auto fee = base::bit_cast<uint128_t>(fee_bytes);
   if (fee == 0) {

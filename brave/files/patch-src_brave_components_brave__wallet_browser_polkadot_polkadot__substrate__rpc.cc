--- src/brave/components/brave_wallet/browser/polkadot/polkadot_substrate_rpc.cc.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_substrate_rpc.cc
@@ -18,7 +18,7 @@
 #include "base/strings/strcat.h"  // IWYU pragma: export
 #include "base/strings/string_number_conversions.h"
 #include "brave/components/brave_wallet/browser/brave_wallet_utils.h"
-#include "brave/components/brave_wallet/browser/internal/polkadot_extrinsic_rs.h"
+#include "brave/components/brave_wallet/browser/internal/polkadot_extrinsic.rs.h"
 #include "brave/components/brave_wallet/browser/network_manager.h"
 #include "brave/components/brave_wallet/browser/polkadot/polkadot_substrate_rpc_responses.h"
 #include "brave/components/brave_wallet/common/hash_utils.h"
@@ -935,14 +935,15 @@ void PolkadotSubstrateRpc::OnGetPaymentI
         base::unexpected(WalletParsingErrorMessage()));
   }
 
-  auto partial_fee_bytes = parse_fee_info(query_info);
-  if (!partial_fee_bytes.has_value()) {
+  std::array<uint8_t, 16> partial_fee_bytes = {};
+  if (!parse_fee_info(::rust::Slice<const uint8_t>(query_info),
+                      partial_fee_bytes)) {
     return std::move(callback).Run(
         base::unexpected(WalletParsingErrorMessage()));
   }
 
   return std::move(callback).Run(
-      base::ok(base::bit_cast<uint128_t>(*partial_fee_bytes)));
+      base::ok(base::bit_cast<uint128_t>(partial_fee_bytes)));
 }
 
 void PolkadotSubstrateRpc::GetEvents(

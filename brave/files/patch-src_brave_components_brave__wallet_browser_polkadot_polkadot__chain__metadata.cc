--- src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata.cc.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata.cc
@@ -28,12 +28,14 @@ bool PolkadotChainMetadata::operator==(
 
 std::optional<PolkadotChainMetadata> PolkadotChainMetadata::FromBytes(
     base::span<const uint8_t> metadata_bytes) {
-  auto result = parse_chain_metadata_from_scale(metadata_bytes);
-  if (!result.has_value()) {
+  auto result = parse_chain_metadata_from_scale(
+      ::rust::Slice<const uint8_t>(metadata_bytes));
+  if (!result->is_ok()) {
     return std::nullopt;
   }
 
-  return PolkadotChainMetadata(*result);
+  auto parsed = result->unwrap();
+  return PolkadotChainMetadata(*parsed);
 }
 
 // static
@@ -65,7 +67,7 @@ PolkadotChainMetadata PolkadotChainMetad
   metadata->has_assets_pallet = has_assets_pallet;
   metadata->ss58_prefix = ss58_prefix;
   metadata->spec_version = spec_version;
-  metadata->signed_extensions.bytes = signed_extensions;
+  metadata->signed_extensions = signed_extensions;
 
   return metadata;
 }

--- src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata_prefs.cc.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata_prefs.cc
@@ -166,7 +166,7 @@ PolkadotChainMetadataPrefs::GetChainMeta
   }
 
   if (!ReadBytes(*chain_metadata, kSignedExtensions,
-                 metadata->signed_extensions.bytes)) {
+                 metadata->signed_extensions)) {
     return std::nullopt;
   }
 
@@ -234,7 +234,7 @@ bool PolkadotChainMetadataPrefs::SetChai
   value.Set(kAssetsTransferKeepAliveCallIndex,
             assets_transfer_keep_alive_call_index);
   value.Set(kSignedExtensions,
-            base::HexEncodeLower(metadata->signed_extensions.bytes));
+            base::HexEncodeLower(metadata->signed_extensions));
   value.Set(kSs58Prefix, ss58_prefix);
   value.Set(kSpecVersion, spec_version);
   ScopedDictPrefUpdate update(profile_prefs_.get(),

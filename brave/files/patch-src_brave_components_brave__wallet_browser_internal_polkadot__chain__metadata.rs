--- src/brave/components/brave_wallet/browser/internal/polkadot_chain_metadata.rs.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/internal/polkadot_chain_metadata.rs
@@ -3,7 +3,7 @@
 // License, v. 2.0. If a copy of the MPL was not distributed with this file,
 // You can obtain one at https://mozilla.org/MPL/2.0/.
 
-use crate::{CxxPolkadotChainMetadata, Error, SignedExtensions};
+use crate::{CxxPolkadotChainMetadata, CxxPolkadotChainMetadataResult, Error};
 use parity_scale_codec::{Compact, Decode};
 use std::collections::HashMap;
 
@@ -309,7 +309,7 @@ fn get_call_index(
 }
 
 #[repr(u8)]
-pub(crate) enum SignedExtension {
+pub enum SignedExtension {
     AuthorizeValueTransfer = 1,
     AuthorizeCall,
     AsPgas,
@@ -345,8 +345,8 @@ impl TryFrom<u8> for SignedExtension {
             return Err(Error::UnknownSignedExtension);
         }
 
-        // SAFETY: safe because our enum has u8 representation and we just
-        // checked the value above.
+        // SAFETY: safe because our enum has u8 representation and we just checked the
+        // value above.
         let extension = unsafe { std::mem::transmute::<_, SignedExtension>(value) };
         Ok(extension)
     }
@@ -410,8 +410,8 @@ fn parse_signed_extensions(input: &mut &
 
         let _ty: u32 = decode_type_id(input)?; // ty
 
-        // These denote the actual type of the extension for use in generating
-        // the "implicit" data part of the signature payload.
+        // These denote the actual type of the extension for use in generating the
+        // "implicit" data part of the signature payload.
         let _: u32 = decode_type_id(input)?; // additional_signed
         Ok(())
     })?;
@@ -562,12 +562,12 @@ fn parse_chain_metadata_fields(bytes: &[
         has_assets_pallet,
         ss58_prefix,
         spec_version,
-        signed_extensions: SignedExtensions { bytes: signed_extensions },
+        signed_extensions,
     })
 }
 
-pub fn parse_chain_metadata_from_scale(
+pub(super) fn parse_chain_metadata_from_scale(
     metadata_bytes: &[u8],
-) -> Result<CxxPolkadotChainMetadata, String> {
-    parse_chain_metadata_fields(metadata_bytes).map_err(|e| e.to_string())
+) -> Box<CxxPolkadotChainMetadataResult> {
+    Box::new(CxxPolkadotChainMetadataResult(parse_chain_metadata_fields(metadata_bytes)))
 }

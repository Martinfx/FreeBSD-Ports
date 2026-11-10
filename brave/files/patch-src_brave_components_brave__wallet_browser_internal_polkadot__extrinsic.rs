--- src/brave/components/brave_wallet/browser/internal/polkadot_extrinsic.rs.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/internal/polkadot_extrinsic.rs
@@ -30,46 +30,156 @@ const EXTRINSIC_FAILED_VARIANT_INDEX: u8
 // existential deposit.
 const TRANSFER_ALL_KEEP_ALIVE: bool = false;
 
-/// Signed extension identifiers, zero-padded. A separate type because
-/// `Default` can't be derived for `[u8; 64]`, and every field needs `Default`
-/// for Crubit to emit `CxxPolkadotChainMetadata` as a C++ aggregate.
-#[derive(Clone, Copy, PartialEq)]
-pub struct SignedExtensions {
-    pub bytes: [u8; 64],
-}
+#[cxx::bridge(namespace = brave_wallet)]
+mod ffi {
+    #[derive(Clone, Copy, PartialEq)]
+    pub struct CxxPolkadotChainMetadata {
+        pub system_pallet_index: u8,
+        pub balances_pallet_index: u8,
+        pub transaction_payment_pallet_index: u8,
+        pub transfer_allow_death_call_index: u8,
+        pub transfer_keep_alive_call_index: u8,
+        pub transfer_all_call_index: u8,
+        pub assets_pallet_index: u8,
+        pub assets_transfer_all_call_index: u8,
+        pub assets_transfer_keep_alive_call_index: u8,
+        pub has_assets_pallet: bool,
+        pub ss58_prefix: u16,
+        pub spec_version: u32,
+        pub signed_extensions: [u8; 64],
+    }
 
-impl Default for SignedExtensions {
-    fn default() -> Self {
-        Self { bytes: [0; 64] }
+    /// Holds bytes used for signature payloads and signed extrinsics.
+    pub struct CxxPolkadotExtrinsic {
+        pub bytes: Vec<u8>,
     }
-}
 
-// `repr(C)` keeps the C++ field order matching the declaration order here, as
-// designated initializers require.
-#[repr(C)]
-#[derive(Clone, Copy, PartialEq, Default)]
-pub struct CxxPolkadotChainMetadata {
-    pub system_pallet_index: u8,
-    pub balances_pallet_index: u8,
-    pub transaction_payment_pallet_index: u8,
-    pub transfer_allow_death_call_index: u8,
-    pub transfer_keep_alive_call_index: u8,
-    pub transfer_all_call_index: u8,
-    pub assets_pallet_index: u8,
-    pub assets_transfer_all_call_index: u8,
-    pub assets_transfer_keep_alive_call_index: u8,
-    pub has_assets_pallet: bool,
-    pub ss58_prefix: u16,
-    pub spec_version: u32,
-    pub signed_extensions: SignedExtensions,
+    extern "Rust" {
+        fn compact_scale_encode_u32(x: u32) -> Vec<u8>;
+        fn scale_encode_string(value: &[u8]) -> Vec<u8>;
+
+        type CxxPolkadotChainMetadataResult;
+
+        fn is_ok(self: &CxxPolkadotChainMetadataResult) -> bool;
+        fn error_message(self: &CxxPolkadotChainMetadataResult) -> String;
+        fn unwrap(self: &mut CxxPolkadotChainMetadataResult) -> Box<CxxPolkadotChainMetadata>;
+
+        fn parse_chain_metadata_from_scale(
+            metadata_bytes: &[u8],
+        ) -> Box<CxxPolkadotChainMetadataResult>;
+
+        type CxxPolkadotExtrinsicResult;
+
+        fn is_ok(self: &CxxPolkadotExtrinsicResult) -> bool;
+        fn error_message(self: &CxxPolkadotExtrinsicResult) -> String;
+        fn unwrap(self: &mut CxxPolkadotExtrinsicResult) -> Box<CxxPolkadotExtrinsic>;
+
+        fn scale_encode_mortality(number: u32, period: u32) -> [u8; 2];
+
+        fn generate_extrinsic_signature_payload(
+            chain_metadata: &CxxPolkadotChainMetadata,
+            sender_nonce: u32,
+            send_amount_bytes: &[u8; 16],
+            transfer_all: bool,
+            recipient: &[u8; 32],
+            spec_version: u32,
+            transaction_version: u32,
+            block_number: u32,
+            genesis_hash: &[u8; 32],
+            block_hash: &[u8; 32],
+        ) -> Box<CxxPolkadotExtrinsicResult>;
+
+        fn generate_assets_extrinsic_signature_payload(
+            chain_metadata: &CxxPolkadotChainMetadata,
+            sender_nonce: u32,
+            send_amount_bytes: &[u8; 16],
+            transfer_all: bool,
+            recipient: &[u8; 32],
+            asset_id: u32,
+            spec_version: u32,
+            transaction_version: u32,
+            block_number: u32,
+            genesis_hash: &[u8; 32],
+            block_hash: &[u8; 32],
+        ) -> Box<CxxPolkadotExtrinsicResult>;
+
+        fn make_signed_extrinsic(
+            chain_metadata: &CxxPolkadotChainMetadata,
+            sender_pubkey: &[u8; 32],
+            recipient_pubkey: &[u8; 32],
+            send_amount_bytes: &[u8; 16],
+            transfer_all: bool,
+            signature: &[u8; 64],
+            block_number: u32,
+            sender_nonce: u32,
+        ) -> Box<CxxPolkadotExtrinsicResult>;
+
+        fn make_signed_asset_transfer_extrinsic(
+            chain_metadata: &CxxPolkadotChainMetadata,
+            sender_pubkey: &[u8; 32],
+            recipient_pubkey: &[u8; 32],
+            send_amount_bytes: &[u8; 16],
+            transfer_all: bool,
+            signature: &[u8; 64],
+            block_number: u32,
+            sender_nonce: u32,
+            asset_id: u32,
+        ) -> Box<CxxPolkadotExtrinsicResult>;
+
+        fn parse_fee_info(input: &[u8], fee_bytes: &mut [u8; 16]) -> bool;
+
+        fn was_extrinsic_successful(
+            events: &[u8],
+            extrinsic_idx: u32,
+            sender: &[u8; 32],
+            chain_metadata: &CxxPolkadotChainMetadata,
+            actual_fee: &mut [u8; 16],
+        ) -> bool;
+
+    }
 }
 
-pub use crate::polkadot_chain_metadata::parse_chain_metadata_from_scale;
+use ffi::CxxPolkadotChainMetadata;
+impl_result!(CxxPolkadotChainMetadata, CxxPolkadotChainMetadataResult);
+
+use ffi::CxxPolkadotExtrinsic;
+impl_result!(CxxPolkadotExtrinsic, CxxPolkadotExtrinsicResult);
+
+use crate::polkadot_chain_metadata::parse_chain_metadata_from_scale;
+
+#[macro_export]
+macro_rules! impl_result {
+    ($t:ident, $r:ident) => {
+        struct $r(Result<$t, Error>);
+
+        impl $r {
+            fn error_message(self: &$r) -> String {
+                match &self.0 {
+                    Err(e) => e.to_string(),
+                    Ok(_) => String::new(),
+                }
+            }
+
+            fn is_ok(self: &$r) -> bool {
+                self.0.is_ok()
+            }
+
+            fn unwrap(self: &mut $r) -> Box<$t> {
+                match std::mem::replace(&mut self.0, Err(Error::AlreadyUnwrapped)) {
+                    Ok(v) => Box::new(v),
+                    Err(e) => panic!("{}", e.to_string()),
+                }
+            }
+        }
+    };
+}
 
 /// Errors that can occur when parsing Polkadot runtime metadata or parsing
 /// extrinsics.
 #[derive(Clone, Debug)]
-pub(crate) enum Error {
+pub enum Error {
+    /// The Result has already been unwrapped.
+    AlreadyUnwrapped,
     /// Invalid SCALE value found.
     InvalidScale,
     /// Invalid metadata such as the wrong pallet index or call index.
@@ -78,15 +188,21 @@ pub(crate) enum Error {
     InvalidLength,
     /// Unknowned SignedExtension
     UnknownSignedExtension,
+    /// SignedExtension overflow (more than we've anticipated).
+    SignedExtensionOverflow,
 }
 
 impl fmt::Display for Error {
     fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
         match self {
+            Error::AlreadyUnwrapped => write!(f, "Already unwrapped."),
             Error::InvalidScale => write!(f, "Invalid SCALE-encoded bytes were found."),
             Error::InvalidMetadata => write!(f, "Invalid chain metadata was encountered."),
             Error::InvalidLength => write!(f, "Invalid length."),
             Error::UnknownSignedExtension => write!(f, "Unknowned SignedExtension encountered."),
+            Error::SignedExtensionOverflow => {
+                write!(f, "SignedExtension overflow was encountered.")
+            }
         }
     }
 }
@@ -115,7 +231,7 @@ fn next_n_bytes<'a>(input: &mut &'a [u8]
 ///
 /// Reference implementation:
 /// https://github.com/polkadot-js/api/blob/9f6a9c53e6822d20e8556649c9b68d31cffc465d/packages/types/src/extrinsic/ExtrinsicEra.ts#L179-L204
-pub fn scale_encode_mortality(number: u32, mut period: u32) -> [u8; 2] {
+fn scale_encode_mortality(number: u32, mut period: u32) -> [u8; 2] {
     period = period.checked_next_power_of_two().unwrap().clamp(4, 1 << 16);
 
     let phase = number % period;
@@ -136,7 +252,7 @@ fn append_extra(
 ) -> Result<(), Error> {
     use polkadot_chain_metadata::SignedExtension;
 
-    for &extension in &chain_metadata.signed_extensions.bytes {
+    for &extension in &chain_metadata.signed_extensions {
         if extension == 0 {
             continue;
         }
@@ -147,9 +263,8 @@ fn append_extra(
 
         use parity_scale_codec::Encode;
 
-        // None encodes to the same underlying 0x00 value, no matter what the
-        // value of Option<T> is, so None::<()> is sufficient for our
-        // purposes.
+        // None encodes to the same underlying 0x00 value, no matter what the value of
+        // Option<T> is, so None::<()> is sufficient for our purposes.
 
         match extension {
             SignedExtension::AuthorizeValueTransfer
@@ -175,8 +290,7 @@ fn append_extra(
                 Compact(0x00_u128).encode_to(buf); /* tip */
             }
             SignedExtension::CheckMetadataHash => {
-                // Disabled is the 0'th variant of the Mode type. Enabled is
-                // index 1.
+                // Disabled is the 0'th variant of the Mode type. Enabled is index 1.
                 buf.extend_from_slice(&[0x00 /* mode */]);
             }
             SignedExtension::AuthorizeCall
@@ -206,7 +320,7 @@ fn append_implicit(
 ) -> Result<(), Error> {
     use polkadot_chain_metadata::SignedExtension;
 
-    for &extension in &chain_metadata.signed_extensions.bytes {
+    for &extension in &chain_metadata.signed_extensions {
         if extension == 0 {
             continue;
         }
@@ -226,16 +340,14 @@ fn append_implicit(
                 buf.extend_from_slice(genesis_hash);
             }
             SignedExtension::CheckMortality => {
-                // Our wallet currently only supports mortal transactions, so we
-                // have to attach a blockhash which denotes
-                // which block is the start of the mortality window.
+                // Our wallet currently only supports mortal transactions, so we have to attach
+                // a blockhash which denotes which block is the start of the mortality window.
                 buf.extend_from_slice(block_hash);
             }
             SignedExtension::CheckMetadataHash => {
-                // Disabled is the 0'th variant of the Mode type. To enable the
-                // metadata checking, the Enabled variant is
-                // index 1 and we require a [u8;32] denoting the
-                // hash.
+                // Disabled is the 0'th variant of the Mode type. To enable the metadata
+                // checking, the Enabled variant is index 1 and we require a [u8;32] denoting
+                // the hash.
                 buf.extend_from_slice(&[0x00 /* mode */]);
             }
             SignedExtension::AuthorizeValueTransfer
@@ -345,8 +457,8 @@ fn generate_extrinsic_signature_payload_
         &mut buf,
     )?;
 
-    // If our payload exceeds 256 bytes, hash it down to 32 bytes as
-    // demonstarted by the polkadot-js implementation here:
+    // If our payload exceeds 256 bytes, hash it down to 32 bytes as demonstarted by
+    // the polkadot-js implementation here:
     // https://github.com/polkadot-js/api/blob/9f6a9c53e6822d20e8556649c9b68d31cffc465d/packages/types/src/extrinsic/util.ts#L10-L17
     // https://github.com/polkadot-js/common/blob/bf63a0ebf655312f54aa37350d244df3d05e4e32/packages/util-crypto/src/blake2/asU8a.ts#L25-L34
     if buf.len() > 256 {
@@ -359,7 +471,7 @@ fn generate_extrinsic_signature_payload_
     Ok(buf)
 }
 
-pub fn generate_extrinsic_signature_payload(
+fn generate_extrinsic_signature_payload(
     chain_metadata: &CxxPolkadotChainMetadata,
     sender_nonce: u32,
     send_amount_bytes: &[u8; 16],
@@ -370,8 +482,8 @@ pub fn generate_extrinsic_signature_payl
     block_number: u32,
     genesis_hash: &[u8; 32],
     block_hash: &[u8; 32],
-) -> Result<Vec<u8>, String> {
-    generate_extrinsic_signature_payload_impl(
+) -> Box<CxxPolkadotExtrinsicResult> {
+    let result = generate_extrinsic_signature_payload_impl(
         chain_metadata,
         sender_nonce,
         send_amount_bytes,
@@ -384,10 +496,12 @@ pub fn generate_extrinsic_signature_payl
         genesis_hash,
         block_hash,
     )
-    .map_err(|e| e.to_string())
+    .map(|bytes| CxxPolkadotExtrinsic { bytes });
+
+    Box::new(CxxPolkadotExtrinsicResult(result))
 }
 
-pub fn generate_assets_extrinsic_signature_payload(
+fn generate_assets_extrinsic_signature_payload(
     chain_metadata: &CxxPolkadotChainMetadata,
     sender_nonce: u32,
     send_amount_bytes: &[u8; 16],
@@ -399,8 +513,8 @@ pub fn generate_assets_extrinsic_signatu
     block_number: u32,
     genesis_hash: &[u8; 32],
     block_hash: &[u8; 32],
-) -> Result<Vec<u8>, String> {
-    generate_extrinsic_signature_payload_impl(
+) -> Box<CxxPolkadotExtrinsicResult> {
+    let result = generate_extrinsic_signature_payload_impl(
         chain_metadata,
         sender_nonce,
         send_amount_bytes,
@@ -413,7 +527,9 @@ pub fn generate_assets_extrinsic_signatu
         genesis_hash,
         block_hash,
     )
-    .map_err(|e| e.to_string())
+    .map(|bytes| CxxPolkadotExtrinsic { bytes });
+
+    Box::new(CxxPolkadotExtrinsicResult(result))
 }
 
 fn make_signed_transfer_extrinsic_impl(
@@ -486,7 +602,7 @@ fn make_signed_transfer_extrinsic_impl(
     Ok(buf)
 }
 
-pub fn make_signed_extrinsic(
+fn make_signed_extrinsic(
     chain_metadata: &CxxPolkadotChainMetadata,
     sender_pubkey: &[u8; 32],
     recipient_pubkey: &[u8; 32],
@@ -495,8 +611,8 @@ pub fn make_signed_extrinsic(
     signature: &[u8; 64],
     block_number: u32,
     sender_nonce: u32,
-) -> Result<Vec<u8>, String> {
-    make_signed_transfer_extrinsic_impl(
+) -> Box<CxxPolkadotExtrinsicResult> {
+    let result = make_signed_transfer_extrinsic_impl(
         chain_metadata,
         sender_pubkey,
         recipient_pubkey,
@@ -507,10 +623,12 @@ pub fn make_signed_extrinsic(
         sender_nonce,
         None,
     )
-    .map_err(|e| e.to_string())
+    .map(|bytes| CxxPolkadotExtrinsic { bytes });
+
+    Box::new(CxxPolkadotExtrinsicResult(result))
 }
 
-pub fn make_signed_asset_transfer_extrinsic(
+fn make_signed_asset_transfer_extrinsic(
     chain_metadata: &CxxPolkadotChainMetadata,
     sender_pubkey: &[u8; 32],
     recipient_pubkey: &[u8; 32],
@@ -520,8 +638,8 @@ pub fn make_signed_asset_transfer_extrin
     block_number: u32,
     sender_nonce: u32,
     asset_id: u32,
-) -> Result<Vec<u8>, String> {
-    make_signed_transfer_extrinsic_impl(
+) -> Box<CxxPolkadotExtrinsicResult> {
+    let result = make_signed_transfer_extrinsic_impl(
         chain_metadata,
         sender_pubkey,
         recipient_pubkey,
@@ -532,7 +650,9 @@ pub fn make_signed_asset_transfer_extrin
         sender_nonce,
         Some(asset_id),
     )
-    .map_err(|e| e.to_string())
+    .map(|bytes| CxxPolkadotExtrinsic { bytes });
+
+    Box::new(CxxPolkadotExtrinsicResult(result))
 }
 
 // Definition of the type's binary representation is provided here:
@@ -543,46 +663,55 @@ pub fn make_signed_asset_transfer_extrin
 // weight = {ref_time (as Compact<u64>), proof_size (as Compact<u64>)}
 // class = 0x00, 0x01, or 0x02
 // partial_fee = LE bytes representing U128
-pub fn parse_fee_info(input: &[u8]) -> Option<[u8; 16]> {
-    // Normally in C++, a reference is an immutable thing that once it's bound
-    // to an object, it can never re-alias. In Rust, a reference _is_ a
-    // pointer. The parity-scale-codec crate takes advantage of this and its
-    // API mutates the input pointer, advancing it as it parses.
+fn parse_fee_info(input: &[u8], fee_bytes: &mut [u8; 16]) -> bool {
+    // Normally in C++, a reference is an immutable thing that once it's bound to an
+    // object, it can never re-alias. In Rust, a reference _is_ a pointer. The
+    // parity-scale-codec crate takes advantage of this and its API mutates the
+    // input pointer, advancing it as it parses.
     let mut input = input;
 
-    let _ref_time = <Compact<u64>>::decode(&mut input).ok()?;
-    let _proof_size = <Compact<u64>>::decode(&mut input).ok()?;
+    let ref_time = <Compact<u64>>::decode(&mut input);
+    if ref_time.is_err() {
+        return false;
+    }
+
+    let proof_size = <Compact<u64>>::decode(&mut input);
+    if proof_size.is_err() {
+        return false;
+    }
 
     const CLASS_NORMAL: u8 = 0;
     const CLASS_OPERATIONAL: u8 = 1;
     const CLASS_MANDATORY: u8 = 2;
 
-    let class = next_n_bytes(&mut input, 1).ok()?;
+    let Ok(class) = next_n_bytes(&mut input, 1) else { return false };
     match class[0] {
         // These are the only valid values
         // https://github.com/polkadot-js/api/blob/eb34741c871ca8d029a9706ae989ba8ce865db0f/packages/types-support/src/metadata/v15/polkadot-types.json#L1330-L1349
         CLASS_NORMAL | CLASS_OPERATIONAL | CLASS_MANDATORY => {}
-        _ => return None,
+        _ => return false,
     }
 
-    let fee_le_bytes = next_n_bytes(&mut input, 16).ok()?;
+    let Ok(fee_le_bytes) = next_n_bytes(&mut input, 16) else { return false };
     if !input.is_empty() {
         // Trailing octets, assume invalid input.
-        return None;
+        return false;
     }
 
-    fee_le_bytes.try_into().ok()
+    fee_bytes.copy_from_slice(fee_le_bytes);
+
+    true
 }
 
-pub fn compact_scale_encode_u32(x: u32) -> Vec<u8> {
+fn compact_scale_encode_u32(x: u32) -> Vec<u8> {
     Compact(x).encode()
 }
 
-pub fn scale_encode_string(value: &[u8]) -> Vec<u8> {
+fn scale_encode_string(value: &[u8]) -> Vec<u8> {
     value.encode()
 }
 
-pub fn was_extrinsic_successful(
+fn was_extrinsic_successful(
     events: &[u8],
     extrinsic_idx: u32,
     sender: &[u8; 32],
@@ -626,18 +755,16 @@ pub fn was_extrinsic_successful(
     // But in general, it seems like the events flow can become quite complex:
     // https://polkadot.subscan.io/extrinsic/30123219-2
     // The thing to note is that the extrinsic always ends with the same two
-    // events, the fee was paid and the system gave the extrinsic a final
-    // status.
+    // events, the fee was paid and the system gave the extrinsic a final status.
     //
     // In Polkadot, an event is defined as: {phase, event, topics}
     // https://github.com/polkadot-js/api/blob/eb34741c871ca8d029a9706ae989ba8ce865db0f/packages/types-support/src/metadata/v15/polkadot-types.json#L519-L542
     //
     // Because the events are a massive binary blob that rely on quite a bit of
-    // Polkadot runtime metadata to fully parse, we just probe for the two
-    // events for our extrinsic that we care about: the transaction fee paid
-    // and the final status. We can theoretically probe for everything such
-    // as who the fee was paid out to but it isn't strictly required for our
-    // current needs.
+    // Polkadot runtime metadata to fully parse, we just probe for the two events
+    // for our extrinsic that we care about: the transaction fee paid and the final
+    // status. We can theoretically probe for everything such as who the fee was
+    // paid out to but it isn't strictly required for our current needs.
 
     // We first probe for the balances(Withdraw) event, so that we can use the
     // withdrawn fee as a sanity check when we probe for our TransactionFeePaid
@@ -680,8 +807,7 @@ pub fn was_extrinsic_successful(
     transaction_fee_paid_needle[6] = TRANSACTION_FEE_PAID_VARIANT_INDEX;
     transaction_fee_paid_needle[7..39].copy_from_slice(sender);
 
-    // Use `find` here because we've located the start of our event sequence
-    // above.
+    // Use `find` here because we've located the start of our event sequence above.
     let Some(needle_idx) = memchr::memmem::find(events, &transaction_fee_paid_needle) else {
         return false;
     };

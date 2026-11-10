--- src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata.h.orig	2026-11-02 23:22:33 UTC
+++ src/brave/components/brave_wallet/browser/polkadot/polkadot_chain_metadata.h
@@ -12,7 +12,7 @@
 #include <optional>
 
 #include "base/containers/span.h"
-#include "brave/components/brave_wallet/browser/internal/polkadot_extrinsic_rs.h"
+#include "brave/components/brave_wallet/browser/internal/polkadot_extrinsic.rs.h"
 
 namespace brave_wallet {
 
@@ -61,9 +61,9 @@ class PolkadotChainMetadata {
   const CxxPolkadotChainMetadata& operator*() const;
 
   // We want to expose the native data members of the underlying
-  // CxxPolkadotChainMetadata struct, but Crubit marks generated structs as
-  // final so we can't simply inherit from them publicly. To make accessing the
-  // data members more ergonomic, we overload the arrow operator to return a
+  // CxxPolkadotChainMetadata struct, but the cxx crate marks generated structs
+  // as final so we can't simply inherit from them publicly. To make accessing
+  // the data members more ergonomic, we overload the arrow operator to return a
   // pointer to the generated struct.
   CxxPolkadotChainMetadata* operator->();
   const CxxPolkadotChainMetadata* operator->() const;

--- src/lib.rs.orig
+++ src/lib.rs
@@ -27,6 +27,8 @@
     feature = "flutter"
 )))]
 pub mod ui;
+#[cfg(all(feature = "egui", not(any(target_os = "android", target_os = "ios", feature = "cli", feature = "flutter"))))]
+pub mod ui_egui;
 mod version;
 pub use version::*;
 #[cfg(any(target_os = "android", target_os = "ios", feature = "flutter"))]

--- libs/enigo/src/lib.rs.orig	2024-06-05 08:47:02 UTC
+++ libs/enigo/src/lib.rs
@@ -73,9 +73,9 @@ pub use macos::Enigo;
 #[cfg(target_os = "macos")]
 pub use macos::ENIGO_INPUT_EXTRA_VALUE;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 mod linux;
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub use crate::linux::Enigo;
 
 /// DSL parser module

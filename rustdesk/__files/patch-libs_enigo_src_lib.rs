--- libs/enigo/src/lib.rs.orig	2025-03-29 10:41:15 UTC
+++ libs/enigo/src/lib.rs
@@ -73,9 +73,9 @@ pub use macos::ENIGO_INPUT_EXTRA_VALUE;
 #[cfg(target_os = "macos")]
 pub use macos::ENIGO_INPUT_EXTRA_VALUE;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod linux;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub use crate::linux::Enigo;
 
 /// DSL parser module

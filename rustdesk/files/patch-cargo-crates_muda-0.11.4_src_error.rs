--- cargo-crates/muda-0.11.4/src/error.rs.orig	2024-06-07 11:57:06 UTC
+++ cargo-crates/muda-0.11.4/src/error.rs
@@ -13,13 +13,13 @@ pub enum Error {
     #[cfg(windows)]
     #[error("This menu has not been initialized for this hwnd`")]
     NotInitialized,
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     #[error("This menu has not been initialized for this gtk window`")]
     NotInitialized,
     #[cfg(windows)]
     #[error("This menu has already been initialized for this hwnd`")]
     AlreadyInitialized,
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     #[error("This menu has already been initialized for this gtk window`")]
     AlreadyInitialized,
     #[error("{0}")]

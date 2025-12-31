--- cargo-crates/muda-0.13.5/src/error.rs.orig	2025-03-29 21:21:33 UTC
+++ cargo-crates/muda-0.13.5/src/error.rs
@@ -15,13 +15,13 @@ pub enum Error {
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
     #[error(transparent)]

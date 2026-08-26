--- cargo-crates/system_shutdown-4.0.1/src/lib.rs.orig	2025-03-29 12:59:07 UTC
+++ cargo-crates/system_shutdown-4.0.1/src/lib.rs
@@ -23,6 +23,10 @@ mod os;
 #[path = "linux.rs"]
 mod os;
 
+#[cfg(target_os = "freebsd")]
+#[path = "linux.rs"]
+mod os;
+
 #[cfg(target_os = "macos")]
 #[path = "macos.rs"]
 mod os;

--- cargo-crates/muda-0.11.4/src/platform_impl/mod.rs.orig	2024-06-07 11:43:38 UTC
+++ cargo-crates/muda-0.11.4/src/platform_impl/mod.rs
@@ -5,7 +5,7 @@
 #[cfg(target_os = "windows")]
 #[path = "windows/mod.rs"]
 mod platform;
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 #[path = "gtk/mod.rs"]
 mod platform;
 #[cfg(target_os = "macos")]

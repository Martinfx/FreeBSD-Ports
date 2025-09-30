--- cargo-crates/muda-0.13.5/src/platform_impl/mod.rs.orig	2025-03-29 21:24:55 UTC
+++ cargo-crates/muda-0.13.5/src/platform_impl/mod.rs
@@ -5,7 +5,7 @@ mod platform;
 #[cfg(target_os = "windows")]
 #[path = "windows/mod.rs"]
 mod platform;
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 #[path = "gtk/mod.rs"]
 mod platform;
 #[cfg(target_os = "macos")]

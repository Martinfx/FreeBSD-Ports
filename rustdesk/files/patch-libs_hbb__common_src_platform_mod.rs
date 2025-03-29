--- libs/hbb_common/src/platform/mod.rs.orig	2025-03-29 10:37:36 UTC
+++ libs/hbb_common/src/platform/mod.rs
@@ -1,4 +1,4 @@
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub mod linux;
 
 #[cfg(target_os = "macos")]

--- libs/hbb_common/src/platform/mod.rs.orig	2024-06-07 08:23:02 UTC
+++ libs/hbb_common/src/platform/mod.rs
@@ -1,3 +1,6 @@
+#[cfg(target_os = "freebsd")]
+pub mod linux;
+
 #[cfg(target_os = "linux")]
 pub mod linux;
 

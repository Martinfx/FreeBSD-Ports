--- libs/clipboard/src/platform/mod.rs.orig	2024-06-07 08:26:39 UTC
+++ libs/clipboard/src/platform/mod.rs
@@ -15,13 +15,13 @@ pub fn create_cliprdr_context(
 }
 
 #[cfg(feature = "unix-file-copy-paste")]
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 /// use FUSE for file pasting on these platforms
 pub mod fuse;
 #[cfg(feature = "unix-file-copy-paste")]
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 pub mod unix;
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 pub fn create_cliprdr_context(
     _enable_files: bool,
     _enable_others: bool,
@@ -82,7 +82,7 @@ impl CliprdrServiceContext for DummyCliprdrContext {
 }
 
 #[cfg(feature = "unix-file-copy-paste")]
-#[cfg(any(target_os = "linux", target_os = "macos"))]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 // begin of epoch used by microsoft
 // 1601-01-01 00:00:00 + LDAP_EPOCH_DELTA*(100 ns) = 1970-01-01 00:00:00
 const LDAP_EPOCH_DELTA: u64 = 116444772610000000;

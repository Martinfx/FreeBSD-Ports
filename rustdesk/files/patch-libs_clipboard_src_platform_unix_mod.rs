--- libs/clipboard/src/platform/unix/mod.rs.orig	2024-06-07 08:27:33 UTC
+++ libs/clipboard/src/platform/unix/mod.rs
@@ -19,12 +19,12 @@ use crate::{
 };
 
 use self::local_file::LocalFile;
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 use self::url::{encode_path_to_uri, parse_plain_uri_list};
 
 use super::fuse::FuseServer;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 /// clipboard implementation of x11
 pub mod x11;
 
@@ -34,7 +34,7 @@ pub mod ns_clipboard;
 
 pub mod local_file;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub mod url;
 
 // not actual format id, just a placeholder
@@ -73,7 +73,7 @@ trait SysClipboard: Send + Sync {
     fn get_file_list(&self) -> Vec<PathBuf>;
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 fn get_sys_clipboard(ignore_path: &PathBuf) -> Result<Box<dyn SysClipboard>, CliprdrError> {
     #[cfg(feature = "wayland")]
     {

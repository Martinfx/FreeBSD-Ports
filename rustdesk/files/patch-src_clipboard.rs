--- src/clipboard.rs.orig	2025-03-29 13:11:31 UTC
+++ src/clipboard.rs
@@ -110,7 +110,7 @@ pub fn try_empty_clipboard_files(_side: ClipboardSide,
 
 #[cfg(feature = "unix-file-copy-paste")]
 pub fn try_empty_clipboard_files(_side: ClipboardSide, _conn_id: i32) {
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     std::thread::spawn(move || {
         let mut ctx = CLIPBOARD_CTX.lock().unwrap();
         if ctx.is_none() {
@@ -217,11 +217,11 @@ impl ClipboardContext {
 impl ClipboardContext {
     pub fn new() -> ResultType<ClipboardContext> {
         let board;
-        #[cfg(not(target_os = "linux"))]
+        #[cfg(not(target_os = "freebsd"))]
         {
             board = arboard::Clipboard::new()?;
         }
-        #[cfg(target_os = "linux")]
+        #[cfg(target_os = "freebsd")]
         {
             let mut i = 1;
             loop {
@@ -355,7 +355,7 @@ impl ClipboardContext {
     fn try_empty_clipboard_files(&mut self, side: ClipboardSide) {
         let _lock = ARBOARD_MTX.lock().unwrap();
         if let Ok(data) = self.get_formats(&[ClipboardFormat::FileUrl]) {
-            #[cfg(target_os = "linux")]
+            #[cfg(target_os = "freebsd")]
             let exclude_path =
                 clipboard::platform::unix::fuse::get_exclude_paths(side == ClipboardSide::Client);
             #[cfg(target_os = "macos")]
@@ -379,7 +379,7 @@ impl ClipboardContext {
 
                 // Don't use `hbb_common::platform::linux::is_kde()` here.
                 // It's not correct in the server process.
-                #[cfg(target_os = "linux")]
+                #[cfg(target_os = "freebsd")]
                 let is_kde_x11 = {
                     let is_kde = std::process::Command::new("sh")
                         .arg("-c")

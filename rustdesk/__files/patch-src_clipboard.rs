--- src/clipboard.rs.orig	2025-11-19 03:39:37 UTC
+++ src/clipboard.rs
@@ -23,7 +23,7 @@ lazy_static::lazy_static! {
     // cache the clipboard msg
     static ref LAST_MULTI_CLIPBOARDS: Arc<Mutex<MultiClipboards>> = Arc::new(Mutex::new(MultiClipboards::new()));
     // For updating in server and getting content in cm.
-    // Clipboard on Linux is "server--clients" mode.
+    // Clipboard on freebsd is "server--clients" mode.
     // The clipboard content is owned by the server and passed to the clients when requested.
     // Plain text is the only exception, it does not require the server to be present.
     static ref CLIPBOARD_CTX: Arc<Mutex<Option<ClipboardContext>>> = Arc::new(Mutex::new(None));
@@ -117,7 +117,7 @@ pub fn check_clipboard_files(
     None
 }
 
-#[cfg(all(target_os = "linux", feature = "unix-file-copy-paste"))]
+#[cfg(all(target_os = "freebsd", feature = "unix-file-copy-paste"))]
 pub fn update_clipboard_files(files: Vec<String>, side: ClipboardSide) {
     if !files.is_empty() {
         std::thread::spawn(move || {
@@ -143,7 +143,7 @@ pub fn try_empty_clipboard_files(_side: ClipboardSide,
         }
         #[allow(unused_mut)]
         if let Some(mut ctx) = ctx.as_mut() {
-            #[cfg(target_os = "linux")]
+            #[cfg(target_os = "freebsd")]
             {
                 use clipboard::platform::unix;
                 if unix::fuse::empty_local_files(_side == ClipboardSide::Client, _conn_id) {
@@ -248,11 +248,11 @@ impl ClipboardContext {
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
@@ -397,7 +397,7 @@ impl ClipboardContext {
         vec![]
     }
 
-    #[cfg(all(feature = "unix-file-copy-paste", target_os = "linux"))]
+    #[cfg(all(feature = "unix-file-copy-paste", target_os = "freebsd"))]
     fn get_file_urls_set_by_rustdesk(data: Vec<ClipboardData>, side: ClipboardSide) -> Vec<String> {
         let exclude_path =
             clipboard::platform::unix::fuse::get_exclude_paths(side == ClipboardSide::Client);
@@ -424,11 +424,11 @@ impl ClipboardContext {
                 // The host-side clear file clipboard `let _ = self.inner.clear();`,
                 // does not work on KDE Plasma for the installed version.
 
-                // Don't use `hbb_common::platform::linux::is_kde()` here.
+                // Don't use `hbb_common::platform::freebsd::is_kde()` here.
                 // It's not correct in the server process.
-                #[cfg(target_os = "linux")]
-                let is_kde_x11 = hbb_common::platform::linux::is_kde_session()
-                    && crate::platform::linux::is_x11();
+                #[cfg(target_os = "freebsd")]
+                let is_kde_x11 = hbb_common::platform::freebsd::is_kde_session()
+                    && crate::platform::freebsd::is_x11();
                 #[cfg(target_os = "macos")]
                 let is_kde_x11 = false;
                 let clear_holder_text = if is_kde_x11 {
@@ -748,7 +748,7 @@ pub fn get_clipboards_msg(client: bool) -> Option<Mess
 }
 
 // We need this mod to notify multiple subscribers when the clipboard changes.
-// Because only one clipboard master(listener) can trigger the clipboard change event multiple listeners are created on Linux(x11).
+// Because only one clipboard master(listener) can trigger the clipboard change event multiple listeners are created on freebsd(x11).
 // https://github.com/rustdesk-org/clipboard-master/blob/4fb62e5b62fb6350d82b571ec7ba94b3cd466695/src/master/x11.rs#L226
 #[cfg(not(target_os = "android"))]
 pub mod clipboard_listener {

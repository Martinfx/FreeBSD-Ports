--- src/platform/mod.rs.orig	2024-06-07 09:28:31 UTC
+++ src/platform/mod.rs
@@ -1,4 +1,4 @@
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub use linux::*;
 #[cfg(target_os = "macos")]
 pub use macos::*;
@@ -17,10 +17,10 @@ pub mod macos;
 #[cfg(target_os = "macos")]
 pub mod delegate;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub mod linux;
 
-#[cfg(target_os = "linux")]
+#[cfg(target_os = "freebsd")]
 pub mod linux_desktop_manager;
 
 #[cfg(not(any(target_os = "android", target_os = "ios")))]
@@ -38,7 +38,7 @@ pub fn installing_service() -> bool {
 }
 
 pub fn is_xfce() -> bool {
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     {
         return std::env::var_os("XDG_CURRENT_DESKTOP") == Some(std::ffi::OsString::from("XFCE"));
     }
@@ -49,7 +49,7 @@ pub fn is_xfce() -> bool {
 }
 
 pub fn breakdown_callback() {
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     crate::input_service::clear_remapped_keycode();
     #[cfg(not(any(target_os = "android", target_os = "ios")))]
     crate::input_service::release_device_modifiers();
@@ -111,7 +111,7 @@ pub fn get_wakelock(_display: bool) -> WakeLock {
 pub(crate) struct InstallingService; // please use new
 
 impl InstallingService {
-    #[cfg(any(target_os = "windows", target_os = "linux"))]
+    #[cfg(any(target_os = "windows", target_os = "freebsd"))]
     pub fn new() -> Self {
         *INSTALLING_SERVICE.lock().unwrap() = true;
         Self

--- crates/concat/src/lib.rs.orig	2026-10-17 10:26:12 UTC
+++ crates/concat/src/lib.rs
@@ -54,11 +54,11 @@
 mod studio;
 mod sysinfo;
 /// Native Wayland file drops, which winit does not report; see the module.
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod wayland_drop;
 /// Elsewhere the listener is a name that starts nothing, so platform.rs
 /// reads the same on every desktop.
-#[cfg(not(any(target_os = "linux", target_os = "android")))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd", target_os = "android")))]
 mod wayland_drop {
     /// Nothing to listen to: no desktop but Linux draws through Wayland.
     pub struct Listener;
@@ -1953,7 +1953,7 @@
 /// writes are written before the window closes.
 fn leave(code: i32) -> ! {
     log::logger().flush();
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     {
         use std::io::Write;
         let _ = std::io::stdout().flush();
@@ -1962,6 +1962,6 @@
         // this one's is touched after it.
         unsafe { libc::_exit(code) }
     }
-    #[cfg(not(target_os = "linux"))]
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
     std::process::exit(code);
 }

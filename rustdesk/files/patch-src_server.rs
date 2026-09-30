--- src/server.rs.orig
+++ src/server.rs
@@ -42,9 +42,9 @@
 pub use clipboard_service::is_clipboard_service_ok;
 #[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub(crate) mod wayland;
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub mod uinput;
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub mod rdp_input;
 #[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub mod dbus;

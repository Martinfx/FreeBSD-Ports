--- src/server.rs.orig
+++ src/server.rs
@@ -46,9 +46,9 @@
 pub(crate) mod wayland;
 #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "drm"))]
 pub(crate) mod drm_capturer;
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub mod uinput;
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub mod rdp_input;
 #[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub mod dbus;

--- src/server/input_service.rs.orig
+++ src/server/input_service.rs
@@ -1,4 +1,4 @@
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 use super::rdp_input::client::{RdpInputKeyboard, RdpInputMouse};
 use super::*;
 use crate::input::*;
@@ -112,8 +112,10 @@
 const KEY_CHAR_START: u64 = 9999;
 
 // XKB keycode for Insert key (evdev KEY_INSERT code 110 + 8 for XKB offset)
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 const XKB_KEY_INSERT: u16 = evdev::Key::KEY_INSERT.code() + 8;
+#[cfg(target_os = "freebsd")]
+const XKB_KEY_INSERT: u16 = 110 + 8;
 
 #[derive(Clone, Default)]
 pub struct MouseCursorSub {
@@ -749,7 +751,7 @@
 // First call set_uinput() will create keyboard and mouse clients.
 // The clients are ipc connections that must live shorter than tokio runtime.
 // Thus this function must not be called in a temporary runtime.
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn setup_uinput(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     // Keyboard and mouse both open /dev/uinput
     // TODO: Make sure there's no race
@@ -771,7 +773,7 @@
     Ok(())
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn setup_rdp_input() -> ResultType<(), Box<dyn std::error::Error>> {
     let mut en = ENIGO.lock()?;
     // Same as `setup_uinput`: the caller is gated on `wayland_use_rdp_input()`.
@@ -802,7 +804,7 @@
     Ok(())
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn update_mouse_resolution(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     set_uinput_resolution(minx, maxx, miny, maxy).await?;
 
@@ -824,7 +826,7 @@
     .await?
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 async fn set_uinput_resolution(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     super::uinput::client::set_resolution(minx, maxx, miny, maxy).await
 }
@@ -2864,3 +2866,19 @@
         assert_eq!(last_peer_abs_sample(), None, "the move of this process came last");
     }
 }
+
+// FreeBSD: no uinput (evdev crate) support yet.
+#[cfg(target_os = "freebsd")]
+pub async fn setup_uinput(_minx: i32, _maxx: i32, _miny: i32, _maxy: i32) -> ResultType<()> {
+    bail!("uinput is not supported on FreeBSD")
+}
+
+#[cfg(target_os = "freebsd")]
+pub async fn update_mouse_resolution(_minx: i32, _maxx: i32, _miny: i32, _maxy: i32) -> ResultType<()> {
+    bail!("uinput is not supported on FreeBSD")
+}
+
+#[cfg(target_os = "freebsd")]
+pub async fn setup_rdp_input() -> ResultType<(), Box<dyn std::error::Error>> {
+    Err("RDP input is not supported on FreeBSD".into())
+}

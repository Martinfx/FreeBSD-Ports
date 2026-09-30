--- src/server/input_service.rs.orig
+++ src/server/input_service.rs
@@ -1,4 +1,4 @@
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 use super::rdp_input::client::{RdpInputKeyboard, RdpInputMouse};
 use super::*;
 use crate::input::*;
@@ -567,7 +567,7 @@
 // First call set_uinput() will create keyboard and mouse clients.
 // The clients are ipc connections that must live shorter than tokio runtime.
 // Thus this function must not be called in a temporary runtime.
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn setup_uinput(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     // Keyboard and mouse both open /dev/uinput
     // TODO: Make sure there's no race
@@ -586,7 +586,7 @@
     Ok(())
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn setup_rdp_input() -> ResultType<(), Box<dyn std::error::Error>> {
     let mut en = ENIGO.lock()?;
     let rdp_info_lock = RDP_SESSION_INFO.lock()?;
@@ -615,7 +615,7 @@
     Ok(())
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 pub async fn update_mouse_resolution(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     set_uinput_resolution(minx, maxx, miny, maxy).await?;
 
@@ -635,7 +635,7 @@
     Ok(())
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+#[cfg(target_os = "linux")]
 async fn set_uinput_resolution(minx: i32, maxx: i32, miny: i32, maxy: i32) -> ResultType<()> {
     super::uinput::client::set_resolution(minx, maxx, miny, maxy).await
 }
@@ -1937,3 +1937,19 @@
         (ControlKey::Delete, true),
     ].iter().map(|(a, b)| (a.value(), b.clone())).collect();
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

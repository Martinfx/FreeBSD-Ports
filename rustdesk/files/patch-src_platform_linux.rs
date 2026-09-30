--- src/platform/linux.rs.orig
+++ src/platform/linux.rs
@@ -255,6 +255,11 @@
     }
 }
 
+// FreeBSD: no uinput support (evdev crate is Linux only).
+#[cfg(target_os = "freebsd")]
+fn start_uinput_service() {}
+
+#[cfg(target_os = "linux")]
 fn start_uinput_service() {
     use crate::server::uinput::service;
     std::thread::spawn(|| {
@@ -708,6 +713,9 @@
         return false;
     }
     let name = get_active_username();
+    if name.is_empty() {
+        return false;
+    }
     if let Ok(res) = run_cmds(&format!("getent passwd {}", name)) {
         return res.contains("/bin/false") || res.contains("/usr/sbin/nologin");
     }

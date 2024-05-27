--- libs/enigo/build.rs.orig	2024-05-11 08:17:55 UTC
+++ libs/enigo/build.rs
@@ -4,18 +4,18 @@ fn main() {}
 #[cfg(target_os = "macos")]
 fn main() {}
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use pkg_config;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::env;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::fs::File;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::io::Write;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::path::Path;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn main() {
     let libraries = [
         "xext",

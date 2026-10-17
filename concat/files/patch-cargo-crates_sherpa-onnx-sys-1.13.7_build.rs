--- cargo-crates/sherpa-onnx-sys-1.13.7/build.rs.orig	2026-10-17 10:26:12 UTC
+++ cargo-crates/sherpa-onnx-sys-1.13.7/build.rs
@@ -418,6 +418,12 @@
 
 fn emit_static_link_directives(target_os: &str) {
     for lib in SHERPA_ONNX_STATIC_LIBS {
+        // On FreeBSD sherpa-onnx is built against misc/onnxruntime, which
+        // is a shared library.
+        if target_os == "freebsd" && *lib == "onnxruntime" {
+            println!("cargo:rustc-link-lib=dylib=onnxruntime");
+            continue;
+        }
         println!("cargo:rustc-link-lib=static={lib}");
     }
 
@@ -428,6 +434,14 @@
             println!("cargo:rustc-link-lib=dylib=pthread");
             println!("cargo:rustc-link-lib=dylib=dl");
         }
+        "freebsd" => {
+            println!("cargo:rustc-link-lib=dylib=c++");
+            println!("cargo:rustc-link-lib=dylib=m");
+            println!("cargo:rustc-link-lib=dylib=pthread");
+            // backtrace(), for the stack trace in sherpa-onnx's and its
+            // dependencies' error messages.
+            println!("cargo:rustc-link-lib=dylib=execinfo");
+        }
         "macos" | "ios" => {
             println!("cargo:rustc-link-lib=dylib=c++");
             println!("cargo:rustc-link-lib=framework=Foundation");

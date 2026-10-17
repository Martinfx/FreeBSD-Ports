--- cargo-crates/skia-bindings-0.153.3/build_support/platform.rs.orig	2026-10-17 10:26:12 UTC
+++ cargo-crates/skia-bindings-0.153.3/build_support/platform.rs
@@ -14,6 +14,7 @@
 pub mod android;
 mod apple;
 pub mod emscripten;
+mod freebsd;
 mod generic;
 pub mod ios;
 pub mod linux;
@@ -101,6 +102,7 @@
         (_, "unknown", "linux", Some("ohos")) => &ohos::OpenHarmony,
         (_, "unknown", "linux", Some("musl")) => &alpine::Musl,
         (_, _, "linux", _) => &linux::Linux,
+        (_, _, "freebsd", _) => &freebsd::FreeBsd,
         _ => &generic::Generic,
     }
 }

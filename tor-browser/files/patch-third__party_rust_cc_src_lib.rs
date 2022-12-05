--- third_party/rust/cc/src/lib.rs.orig	2022-11-30 11:37:40 UTC
+++ third_party/rust/cc/src/lib.rs
@@ -2848,22 +2848,23 @@ impl Tool {
 
     fn with_features(path: PathBuf, clang_driver: Option<&str>, cuda: bool) -> Self {
         // Try to detect family of the tool from its name, falling back to Gnu.
-        let family = if let Some(fname) = path.file_name().and_then(|p| p.to_str()) {
-            if fname.contains("clang-cl") {
-                ToolFamily::Msvc { clang_cl: true }
-            } else if fname.ends_with("cl") || fname == "cl.exe" {
-                ToolFamily::Msvc { clang_cl: false }
-            } else if fname.contains("clang") {
-                match clang_driver {
-                    Some("cl") => ToolFamily::Msvc { clang_cl: true },
-                    _ => ToolFamily::Clang,
-                }
-            } else {
-                ToolFamily::Gnu
-            }
-        } else {
-            ToolFamily::Gnu
-        };
+    //    let family = if let Some(fname) = path.file_name().and_then(|p| p.to_str()) {
+    //        if fname.contains("clang-cl") {
+    //            ToolFamily::Msvc { clang_cl: true }
+    //        } else if fname.ends_with("cl") || fname == "cl.exe" {
+    //            ToolFamily::Msvc { clang_cl: false }
+    //        } else if fname.contains("clang") {
+    //            match clang_driver {
+    //                Some("cl") => ToolFamily::Msvc { clang_cl: true },
+    //                _ => ToolFamily::Clang,
+    //            }
+    //        } else {
+    //            ToolFamily::Gnu
+    //        }
+    //    } else {
+    //        ToolFamily::Gnu
+    //    };
+    let family = ToolFamily::Gnu;
 
         Tool {
             path: path,

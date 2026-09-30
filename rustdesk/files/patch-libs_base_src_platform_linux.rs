--- libs/base/src/platform/linux.rs.orig
+++ libs/base/src/platform/linux.rs
@@ -215,6 +215,20 @@
         }
     }
 
+    // FreeBSD has no logind: the active desktop user is the one running us.
+    #[cfg(target_os = "freebsd")]
+    {
+        let uid = unsafe { libc::getuid() };
+        let name = std::env::var("USER")
+            .ok()
+            .filter(|n| !n.is_empty())
+            .or_else(|| run_cmds("id -un").ok().map(|n| n.trim().to_owned()))
+            .unwrap_or_default();
+        if !name.is_empty() {
+            return line_values(indices, &format!("c1 {} {} seat0", uid, name));
+        }
+    }
+
     line_values(indices, "")
 }
 

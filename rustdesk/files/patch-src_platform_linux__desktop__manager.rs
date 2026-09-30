--- src/platform/linux_desktop_manager.rs.orig
+++ src/platform/linux_desktop_manager.rs
@@ -5,6 +5,7 @@
     LOGIN_MSG_DESKTOP_XSESSION_FAILED,
 };
 use hbb_common::{allow_err, bail, log, rand::prelude::*, tokio::time};
+#[cfg(target_os = "linux")]
 use pam;
 use std::{
     collections::HashMap,
@@ -738,3 +739,34 @@
         "gdm".to_owned()
     }
 }
+
+// FreeBSD: headless X session via Linux-PAM is not supported (yet).
+#[cfg(target_os = "freebsd")]
+mod pam {
+    use hbb_common::{bail, ResultType};
+    pub enum PamItemType {
+        TTY,
+    }
+    pub struct Conversation;
+    impl Conversation {
+        pub fn set_credentials(&mut self, _u: &str, _p: &str) {}
+    }
+    pub struct Client(Conversation);
+    impl Client {
+        pub fn with_password(_service: &str) -> ResultType<Self> {
+            bail!("headless login is not supported on FreeBSD")
+        }
+        pub fn conversation_mut(&mut self) -> &mut Conversation {
+            &mut self.0
+        }
+        pub fn authenticate(&mut self) -> ResultType<()> {
+            bail!("unsupported")
+        }
+        pub fn set_item(&mut self, _t: PamItemType, _v: &str) -> ResultType<()> {
+            bail!("unsupported")
+        }
+        pub fn open_session(&mut self) -> ResultType<()> {
+            bail!("unsupported")
+        }
+    }
+}

--- src/ipc/auth.rs.orig
+++ src/ipc/auth.rs
@@ -221,10 +221,14 @@
 #[cfg(any(any(target_os = "linux", target_os = "freebsd"), target_os = "macos"))]
 #[inline]
 pub(crate) fn peer_uid_from_fd(fd: RawFd) -> Option<u32> {
-    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
+    #[cfg(target_os = "linux")]
     {
         return peer_cred_from_fd(fd).map(|cred| cred.uid as u32);
     }
+    #[cfg(target_os = "freebsd")]
+    {
+        return peer_xucred_from_fd(fd).map(|cred| cred.cr_uid as u32);
+    }
     #[cfg(target_os = "macos")]
     {
         let mut uid = 0;
@@ -240,10 +244,17 @@
 #[cfg(any(any(target_os = "linux", target_os = "freebsd"), target_os = "macos"))]
 #[inline]
 fn peer_pid_from_fd(fd: RawFd) -> Option<u32> {
-    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
+    #[cfg(target_os = "linux")]
     {
         return peer_cred_from_fd(fd).and_then(|cred| (cred.pid > 0).then_some(cred.pid as u32));
     }
+    #[cfg(target_os = "freebsd")]
+    {
+        return peer_xucred_from_fd(fd).and_then(|cred| {
+            let pid = unsafe { cred.cr_pid__c_anonymous_union.cr_pid };
+            (pid > 0).then_some(pid as u32)
+        });
+    }
     #[cfg(target_os = "macos")]
     {
         let mut pid = 0;
@@ -265,7 +276,29 @@
     }
 }
 
-#[cfg(any(target_os = "linux", target_os = "freebsd"))]
+// FreeBSD: LOCAL_PEERCRED (SOL_LOCAL is 0) instead of SO_PEERCRED.
+#[cfg(target_os = "freebsd")]
+#[inline]
+fn peer_xucred_from_fd(fd: RawFd) -> Option<libc::xucred> {
+    let mut cred: libc::xucred = unsafe { std::mem::zeroed() };
+    let mut len = std::mem::size_of::<libc::xucred>() as libc::socklen_t;
+    let rc = unsafe {
+        libc::getsockopt(
+            fd,
+            0,
+            libc::LOCAL_PEERCRED,
+            &mut cred as *mut _ as *mut libc::c_void,
+            &mut len,
+        )
+    };
+    if rc == 0 && cred.cr_version == libc::XUCRED_VERSION {
+        Some(cred)
+    } else {
+        None
+    }
+}
+
+#[cfg(target_os = "linux")]
 #[inline]
 fn peer_cred_from_fd(fd: RawFd) -> Option<libc::ucred> {
     let mut cred: libc::ucred = unsafe { std::mem::zeroed() };

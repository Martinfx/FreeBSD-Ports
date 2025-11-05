--- psst-core/src/lib.rs.orig	2025-11-05 14:42:58 UTC
+++ psst-core/src/lib.rs
@@ -2,10 +2,10 @@ use git_version::git_version;
 
 use git_version::git_version;
 
-pub const GIT_VERSION: &str = git_version!();
-pub const BUILD_TIME: &str = include!(concat!(env!("OUT_DIR"), "/build-time.txt"));
-pub const REMOTE_URL: &str = include!(concat!(env!("OUT_DIR"), "/remote-url.txt"));
-
+pub const GIT_VERSION: &str = "";
+pub const BUILD_TIME: &str = "1970-01-01 00:00:00";
+pub const REMOTE_URL: &str = "https://github.com/jpochyla/psst";
+ 
 pub mod actor;
 pub mod audio;
 pub mod cache;

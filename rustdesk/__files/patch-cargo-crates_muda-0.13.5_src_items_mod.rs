--- cargo-crates/muda-0.13.5/src/items/mod.rs.orig	2025-03-29 21:23:29 UTC
+++ cargo-crates/muda-0.13.5/src/items/mod.rs
@@ -19,7 +19,7 @@ mod test {
     use crate::{CheckMenuItem, IconMenuItem, MenuId, MenuItem, PredefinedMenuItem, Submenu};
 
     #[test]
-    #[cfg_attr(all(miri, not(target_os = "linux")), ignore)]
+    #[cfg_attr(all(miri, not(target_os = "freebsd")), ignore)]
     fn it_returns_same_id() {
         let id = MenuId::new("1");
         assert_eq!(id, MenuItem::with_id(id.clone(), "", true, None).id());
@@ -35,7 +35,7 @@ mod test {
     }
 
     #[test]
-    #[cfg_attr(all(miri, not(target_os = "linux")), ignore)]
+    #[cfg_attr(all(miri, not(target_os = "freebsd")), ignore)]
     fn test_convert_from_id_and_into_id() {
         let id = "TEST ID";
         let expected = MenuId(id.to_string());

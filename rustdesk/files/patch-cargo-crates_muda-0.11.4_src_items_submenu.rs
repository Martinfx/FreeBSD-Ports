--- cargo-crates/muda-0.11.4/src/items/submenu.rs.orig	2024-06-07 11:59:01 UTC
+++ cargo-crates/muda-0.11.4/src/items/submenu.rs
@@ -232,14 +232,14 @@ impl ContextMenu for Submenu {
         self.inner.borrow().detach_menu_subclass_from_hwnd(hwnd)
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn show_context_menu_for_gtk_window(&self, w: &gtk::Window, position: Option<Position>) {
         self.inner
             .borrow_mut()
             .show_context_menu_for_gtk_window(w, position)
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn gtk_context_menu(&self) -> gtk::Menu {
         self.inner.borrow_mut().gtk_context_menu()
     }

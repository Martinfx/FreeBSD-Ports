--- cargo-crates/muda-0.13.5/src/menu.rs.orig	2025-03-29 21:22:21 UTC
+++ cargo-crates/muda-0.13.5/src/menu.rs
@@ -182,7 +182,7 @@ impl Menu {
     /// ## Panics:
     ///
     /// Panics if the gtk event loop hasn't been initialized on the thread.
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     pub fn init_for_gtk_window<W, C>(&self, window: &W, container: Option<&C>) -> crate::Result<()>
     where
         W: gtk::prelude::IsA<gtk::Window>,
@@ -252,7 +252,7 @@ impl Menu {
     }
 
     /// Removes this menu from a [`gtk::Window`]
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     pub fn remove_for_gtk_window<W>(&self, window: &W) -> crate::Result<()>
     where
         W: gtk::prelude::IsA<gtk::Window>,
@@ -267,7 +267,7 @@ impl Menu {
     }
 
     /// Hides this menu from a [`gtk::Window`]
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     pub fn hide_for_gtk_window<W>(&self, window: &W) -> crate::Result<()>
     where
         W: gtk::prelude::IsA<gtk::Window>,
@@ -282,7 +282,7 @@ impl Menu {
     }
 
     /// Shows this menu on a [`gtk::Window`]
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     pub fn show_for_gtk_window<W>(&self, window: &W) -> crate::Result<()>
     where
         W: gtk::prelude::IsA<gtk::Window>,
@@ -297,7 +297,7 @@ impl Menu {
     }
 
     /// Returns whether this menu visible on a [`gtk::Window`]
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     pub fn is_visible_on_gtk_window<W>(&self, window: &W) -> bool
     where
         W: gtk::prelude::IsA<gtk::Window>,
@@ -305,7 +305,7 @@ impl Menu {
         self.inner.borrow().is_visible_on_gtk_window(window)
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     /// Returns the [`gtk::MenuBar`] that is associated with this window if it exists.
     /// This is useful to get information about the menubar for example its height.
     pub fn gtk_menubar_for_gtk_window<W>(self, window: &W) -> Option<gtk::MenuBar>
@@ -357,14 +357,14 @@ impl ContextMenu for Menu {
         self.inner.borrow().detach_menu_subclass_from_hwnd(hwnd)
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn show_context_menu_for_gtk_window(&self, window: &gtk::Window, position: Option<Position>) {
         self.inner
             .borrow_mut()
             .show_context_menu_for_gtk_window(window, position)
     }
 
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn gtk_context_menu(&self) -> gtk::Menu {
         self.inner.borrow_mut().gtk_context_menu()
     }

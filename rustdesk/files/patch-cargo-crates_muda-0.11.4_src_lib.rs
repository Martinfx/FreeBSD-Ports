--- cargo-crates/muda-0.11.4/src/lib.rs.orig	2024-06-07 12:33:07 UTC
+++ cargo-crates/muda-0.11.4/src/lib.rs
@@ -327,11 +327,11 @@ pub trait ContextMenu {
     /// Shows this menu as a context menu inside a [`gtk::Window`]
     ///
     /// - `position` is relative to the window top-left corner, if `None`, the cursor position is used.
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn show_context_menu_for_gtk_window(&self, w: &gtk::Window, position: Option<Position>);
 
     /// Get the underlying gtk menu reserved for context menus.
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn gtk_context_menu(&self) -> gtk::Menu;
 
     /// Shows this menu as a context menu for the specified `NSView`.

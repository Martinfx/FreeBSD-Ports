--- cargo-crates/muda-0.13.5/src/lib.rs.orig	2025-03-29 21:20:16 UTC
+++ cargo-crates/muda-0.13.5/src/lib.rs
@@ -10,7 +10,7 @@
 //!
 //! - Windows
 //! - macOS
-//! - Linux (gtk Only)
+//! - freebsd (gtk Only)
 //!
 //! # Platform-specific notes:
 //!
@@ -18,11 +18,11 @@
 //!   [`TranslateAcceleratorW`](https://docs.rs/windows-sys/latest/windows_sys/Win32/UI/WindowsAndMessaging/fn.TranslateAcceleratorW.html).
 //!   See [`Menu::init_for_hwnd`](https://docs.rs/muda/latest/x86_64-pc-windows-msvc/muda/struct.Menu.html#method.init_for_hwnd) for more details
 //!
-//! # Dependencies (Linux Only)
+//! # Dependencies (freebsd Only)
 //!
 //! `gtk` is used for menus and `libxdo` is used to make the predfined `Copy`, `Cut`, `Paste` and `SelectAll` menu items work. Be sure to install following packages before building:
 //!
-//! #### Arch Linux / Manjaro:
+//! #### Arch freebsd / Manjaro:
 //!
 //! ```sh
 //! pacman -S gtk3 xdotool
@@ -68,20 +68,20 @@
 //! );
 //! ```
 //!
-//! Then add your root menu to a Window on Windows and Linux
+//! Then add your root menu to a Window on Windows and freebsd
 //! or use it as your global app menu on macOS
 //!
 //! ```no_run
 //! # let menu = muda::Menu::new();
 //! # let window_hwnd = 0;
-//! # #[cfg(target_os = "linux")]
+//! # #[cfg(target_os = "freebsd")]
 //! # let gtk_window = gtk::Window::builder().build();
-//! # #[cfg(target_os = "linux")]
+//! # #[cfg(target_os = "freebsd")]
 //! # let vertical_gtk_box = gtk::Box::new(gtk::Orientation::Vertical, 0);
 //! // --snip--
 //! #[cfg(target_os = "windows")]
 //! menu.init_for_hwnd(window_hwnd);
-//! #[cfg(target_os = "linux")]
+//! #[cfg(target_os = "freebsd")]
 //! menu.init_for_gtk_window(&gtk_window, Some(&vertical_gtk_box));
 //! #[cfg(target_os = "macos")]
 //! menu.init_for_nsapp();
@@ -95,7 +95,7 @@
 //! use muda::ContextMenu;
 //! # let menu = muda::Menu::new();
 //! # let window_hwnd = 0;
-//! # #[cfg(target_os = "linux")]
+//! # #[cfg(target_os = "freebsd")]
 //! # let gtk_window = gtk::Window::builder().build();
 //! # #[cfg(target_os = "macos")]
 //! # let nsview = 0 as *mut objc::runtime::Object;
@@ -103,7 +103,7 @@
 //! let position = muda::dpi::PhysicalPosition { x: 100., y: 120. };
 //! #[cfg(target_os = "windows")]
 //! menu.show_context_menu_for_hwnd(window_hwnd, Some(position.into()));
-//! #[cfg(target_os = "linux")]
+//! #[cfg(target_os = "freebsd")]
 //! menu.show_context_menu_for_gtk_window(&gtk_window, Some(position.into()));
 //! #[cfg(target_os = "macos")]
 //! menu.show_context_menu_for_nsview(nsview, Some(position.into()));
@@ -326,11 +326,11 @@ pub trait ContextMenu {
     /// Shows this menu as a context menu inside a [`gtk::Window`]
     ///
     /// - `position` is relative to the window top-left corner, if `None`, the cursor position is used.
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn show_context_menu_for_gtk_window(&self, w: &gtk::Window, position: Option<dpi::Position>);
 
     /// Get the underlying gtk menu reserved for context menus.
-    #[cfg(target_os = "linux")]
+    #[cfg(target_os = "freebsd")]
     fn gtk_context_menu(&self) -> gtk::Menu;
 
     /// Shows this menu as a context menu for the specified `NSView`.

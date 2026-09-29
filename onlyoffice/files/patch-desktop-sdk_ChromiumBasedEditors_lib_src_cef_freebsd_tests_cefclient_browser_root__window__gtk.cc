--- desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/root_window_gtk.cc.orig	2026-09-24 21:58:50 UTC
+++ desktop-sdk/ChromiumBasedEditors/lib/src/cef/freebsd/tests/cefclient/browser/root_window_gtk.cc
@@ -352,6 +352,9 @@ void RootWindowGtk::Show(ShowMode mode)
   // Show the GTK window.
   UseDefaultX11VisualForGtk(GTK_WIDGET(window_));
   gtk_widget_show_all(window_);
+#ifdef ASC_HIDE_WINDOW
+  gtk_widget_hide(window_);
+#endif
 
   if (mode == ShowMinimized) {
     MinimizeWindow(GTK_WINDOW(window_));

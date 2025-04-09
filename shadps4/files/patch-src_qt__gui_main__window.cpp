--- src/qt_gui/main_window.cpp.orig	2025-04-08 06:31:06 UTC
+++ src/qt_gui/main_window.cpp
@@ -253,6 +253,8 @@ void MainWindow::UpdateToolbarButtons() {
 }
 
 void MainWindow::UpdateToolbarButtons() {
+
+    if (!this) return;
     // add toolbar widgets when game is running
     bool showLabels = ui->toggleLabelsAct->isChecked();
 

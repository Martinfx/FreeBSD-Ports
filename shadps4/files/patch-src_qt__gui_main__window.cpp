--- src/qt_gui/main_window.cpp.orig	2025-03-27 20:40:40 UTC
+++ src/qt_gui/main_window.cpp
@@ -253,6 +253,8 @@ void MainWindow::UpdateToolbarButtons() {
 }
 
 void MainWindow::UpdateToolbarButtons() {
+
+    if (!this) return;
     // add toolbar widgets when game is running
     bool showLabels = ui->toggleLabelsAct->isChecked();
 
@@ -1484,7 +1486,7 @@ void MainWindow::StartEmulator(std::filesystem::path p
         return;
     }
     isGameRunning = true;
-#ifdef __APPLE__
+#if defined( __APPLE__) || defined(__FreeBSD__)
     // SDL on macOS requires main thread.
     Core::Emulator emulator;
     emulator.Run(path);

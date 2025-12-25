--- src/app/GUI/mainwindow.cpp.orig	2025-12-23 22:02:19 UTC
+++ src/app/GUI/mainwindow.cpp
@@ -816,7 +816,7 @@ void MainWindow::readSettings(const QString &openProje
         mUI->setDockVisible("Fill and Stroke", false);
     }
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_LINUX || Q_OS_FREEBSD
     if (AppSupport::isWayland()) { // Disable fullscreen on wayland
         isFull = false;
         mViewFullScreenAct->setEnabled(false);

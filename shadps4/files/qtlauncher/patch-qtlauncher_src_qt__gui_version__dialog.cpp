--- qtlauncher/src/qt_gui/version_dialog.cpp.orig	2026-10-02 19:05:42 UTC
+++ qtlauncher/src/qt_gui/version_dialog.cpp
@@ -94,7 +94,7 @@
 #ifdef Q_OS_WIN
         exePath = QFileDialog::getOpenFileName(this, tr("Select executable"), QDir::rootPath(),
                                                tr("Executable (*.exe)"));
-#elif defined(Q_OS_LINUX) || defined(Q_OS_MACOS)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_MACOS) || defined(Q_OS_FREEBSD)
         exePath = QFileDialog::getOpenFileName(this, tr("Select executable"), QDir::rootPath(),
                                                "Executable (*)");
 #endif
@@ -440,6 +440,8 @@
             platform = "linux-sdl";
 #elif defined(Q_OS_MAC)
             platform = "macos-sdl";
+#else
+            platform = "unsupported-platform";
 #endif
             if (versionName.contains("Pre-release", Qt::CaseInsensitive)) {
                 apiUrl = "https://api.github.com/repos/shadps4-emu/shadPS4/releases";
@@ -1116,6 +1118,8 @@
         platformStr = "linux-sdl";
 #elif defined(Q_OS_MAC)
         platformStr = "macos-sdl";
+#else
+        platformStr = "unsupported-platform";
 #endif
         for (const QJsonValue& av : assets) {
             QJsonObject aobj = av.toObject();

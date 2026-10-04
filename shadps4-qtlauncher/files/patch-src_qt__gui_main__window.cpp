--- src/qt_gui/main_window.cpp.orig	2026-10-02 19:05:42 UTC
+++ src/qt_gui/main_window.cpp
@@ -1426,6 +1426,13 @@
     }
 
     QString selectedVersion = m_gui_settings->GetValue(gui::vm_versionSelected).toString();
+#ifdef SHADPS4_SYSTEM_EXECUTABLE
+    // Fall back to the emulator installed by the package manager.
+    if (selectedVersion.isEmpty() && QFileInfo::exists(SHADPS4_SYSTEM_EXECUTABLE)) {
+        selectedVersion = SHADPS4_SYSTEM_EXECUTABLE;
+        m_gui_settings->SetValue(gui::vm_versionSelected, selectedVersion);
+    }
+#endif
     if (selectedVersion.isEmpty()) {
         QMessageBox::warning(this, tr("No Version Selected"),
                              // clang-format off

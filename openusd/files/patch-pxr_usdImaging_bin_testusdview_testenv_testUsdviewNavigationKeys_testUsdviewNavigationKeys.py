--- pxr/usdImaging/bin/testusdview/testenv/testUsdviewNavigationKeys/testUsdviewNavigationKeys.py.orig	2026-04-24 18:55:54 UTC
+++ pxr/usdImaging/bin/testusdview/testenv/testUsdviewNavigationKeys/testUsdviewNavigationKeys.py
@@ -20,7 +20,23 @@ def _popupFileMenu(appController):
     appController._ui.menuFile.exec_()
     appController._processEvents()
 
+def _makeMainWindowActive(appController):
+    # The application's event filter routes the navigation keys to the focus
+    # widget, which only the active window has.  The window system does not
+    # necessarily keep the main window active, e.g. when the window of another
+    # test running at the same time takes the focus, or with focus stealing
+    # prevention, so make it the active window within Qt.
+    mainWindow = appController._mainWindow
+    setActiveWindow = getattr(QtWidgets.QApplication, "setActiveWindow", None)
+    if setActiveWindow:
+        setActiveWindow(mainWindow)
+    else:
+        mainWindow.activateWindow()
+    appController._processEvents()
+
 def _postAndProcessKeyEvent(key, widget, appController):
+    if widget is QtWidgets.QApplication.instance():
+        _makeMainWindowActive(appController)
     event = QtGui.QKeyEvent(QtCore.QEvent.Type.KeyPress,
                             key,
                             QtCore.Qt.KeyboardModifier.NoModifier)

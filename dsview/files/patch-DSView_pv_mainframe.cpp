--- DSView/pv/mainframe.cpp.orig	2024-05-11 03:47:23 UTC
+++ DSView/pv/mainframe.cpp
@@ -1106,7 +1106,7 @@ QWidget* MainFrame::GetBodyView()
     return _mainWindow->GetBodyView();
 }
 
-bool MainFrame::nativeEvent(const QByteArray &eventType, void *message, long *result)
+bool MainFrame::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
 {
 #ifdef _WIN32
 

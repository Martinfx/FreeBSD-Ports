--- DSView/pv/mainframe.h.orig	2024-05-11 03:47:23 UTC
+++ DSView/pv/mainframe.h
@@ -114,8 +114,8 @@ class MainFrame :  (protected)
 
     void changeEvent(QEvent *event) override; 
 
-    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
- 
+    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result);
+
 signals:
     void sig_ParentNativeEvent(int msg);
 

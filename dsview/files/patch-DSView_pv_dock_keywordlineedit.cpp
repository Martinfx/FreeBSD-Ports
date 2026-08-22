--- DSView/pv/dock/keywordlineedit.cpp.orig	2026-08-22 10:33:22 UTC
+++ DSView/pv/dock/keywordlineedit.cpp
@@ -120,7 +120,11 @@ void KeyLineEdit::wheelEvent(QWheelEvent *event)
             int v = new_text.toInt();
             int old_v = v;
 
-            if (event->delta() > 0){
+#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
+            if (event->angleDelta().y() > 0){
+#else
+    	    if (event->delta() > 0){
+#endif
                 v++;
             }
             else{

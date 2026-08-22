--- DSView/pv/view/header.cpp.orig	2026-08-22 09:39:49 UTC
+++ DSView/pv/view/header.cpp
@@ -330,7 +330,7 @@ void Header::wheelEvent(QWheelEvent *event)
     }
 #else
     x = event->x();
-    delta = event->delta();
+    delta = event->angleDelta().y();
     isVertical = event->orientation() == Qt::Vertical;
     pos = event->pos(); 
 #endif

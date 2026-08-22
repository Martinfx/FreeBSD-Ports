--- DSView/pv/view/viewport.cpp.orig	2026-08-22 09:39:49 UTC
+++ DSView/pv/view/viewport.cpp
@@ -1353,7 +1353,7 @@ void Viewport::wheelEvent(QWheelEvent *event)
     }
 #else
     x = event->x();
-    delta = event->delta();
+    delta = event->angleDelta().y();
     isVertical = event->orientation() == Qt::Vertical;
 #endif
 

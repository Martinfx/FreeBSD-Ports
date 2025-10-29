--- test/src/TestUIInteraction.cpp.orig	2025-10-29 07:53:22 UTC
+++ test/src/TestUIInteraction.cpp
@@ -20,6 +20,7 @@
 #include <QGraphicsScene>
 #include <QTimer>
 
+using namespace Catch;
 using QtNodes::BasicGraphicsScene;
 using QtNodes::ConnectionGraphicsObject;
 using QtNodes::ConnectionId;

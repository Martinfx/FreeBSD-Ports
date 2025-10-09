--- test/src/TestUIInteraction.cpp.orig	2025-10-09 16:54:05 UTC
+++ test/src/TestUIInteraction.cpp
@@ -8,7 +8,7 @@
 #include <QtNodes/internal/ConnectionGraphicsObject.hpp>
 #include <QtNodes/Definitions>
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_all.hpp>
 #include <QTest>
 #include <QSignalSpy>
 #include <QGraphicsSceneMouseEvent>
@@ -20,6 +20,7 @@
 #include <QGraphicsScene>
 #include <QTimer>
 
+using namespace Catch;
 using QtNodes::BasicGraphicsScene;
 using QtNodes::ConnectionGraphicsObject;
 using QtNodes::ConnectionId;

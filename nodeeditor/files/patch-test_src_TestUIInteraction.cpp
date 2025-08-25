--- test/src/TestUIInteraction.cpp.orig	2025-08-25 03:04:21 UTC
+++ test/src/TestUIInteraction.cpp
@@ -30,6 +30,7 @@ using QtNodes::PortType;
 using QtNodes::NodeRole;
 using QtNodes::PortIndex;
 using QtNodes::PortType;
+using namespace Catch;
 
 TEST_CASE("UI Interaction - Node Movement", "[ui][visual]")
 {

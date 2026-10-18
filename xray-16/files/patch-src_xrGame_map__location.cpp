--- src/xrGame/map_location.cpp.orig	2026-10-01 00:00:00 UTC
+++ src/xrGame/map_location.cpp
@@ -383,12 +383,13 @@
     {
         bool b_alife = !!ai().get_alife();
 
-        if (b_alife && m_flags.test(eHideInOffline) && !m_owner_se_object->m_bOnline)
+        if (b_alife && m_flags.test(eHideInOffline) && m_owner_se_object && !m_owner_se_object->m_bOnline)
         {
             return;
         }
 
-        if (b_alife && m_owner_se_object->m_flags.test(CSE_ALifeObject::flVisibleForMap) == FALSE)
+        if (b_alife && m_owner_se_object &&
+            m_owner_se_object->m_flags.test(CSE_ALifeObject::flVisibleForMap) == FALSE)
         {
             return;
         }
@@ -460,7 +461,7 @@
         if (b_pointer)
             UpdateSpotPointer(map, GetSpotPointer(sp));
     }
-    else if (Level().name() == map->MapName() && GetSpotPointer(sp))
+    else if (m_owner_se_object && Level().name() == map->MapName() && GetSpotPointer(sp))
     {
         GameGraph::_GRAPH_ID dest_graph_id;
 

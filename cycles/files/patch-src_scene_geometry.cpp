Create the generated attribute of subdivision meshes before they are
tessellated, as the tangents need it: from the Cycles build of
graphics/gaffer (https://github.com/GafferHQ/dependencies), where it
fixes a crash.

--- src/scene/geometry.cpp.orig	2026-03-30 21:43:11 UTC
+++ src/scene/geometry.cpp
@@ -820,6 +820,8 @@ void GeometryManager::device_update(Device *device,
     }
 
     Mesh *mesh = static_cast<Mesh *>(geom);
+    /* Apply generated attribute if needed or remove if not needed */
+    mesh->update_generated(scene);
 
     if (num_tessellation && mesh->need_tesselation()) {
       {
@@ -848,8 +850,6 @@ void GeometryManager::device_update(Device *device,
       mesh->tessellate(subd_params);
     }
 
-    /* Apply generated attribute if needed or remove if not needed */
-    mesh->update_generated(scene);
     /* Apply tangents for generated and UVs (if any need them) or remove if not needed */
     mesh->update_tangents(scene, true);
     if (!mesh->has_true_displacement()) {

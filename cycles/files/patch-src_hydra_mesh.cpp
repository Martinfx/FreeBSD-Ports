--- src/hydra/mesh.cpp.orig	2026-03-30 21:43:11 UTC
+++ src/hydra/mesh.cpp
@@ -55,7 +55,11 @@ VtValue ComputeTriangulatedFaceVaryingPr
                                               HdMeshUtil &meshUtil)
 {
   if (meshUtil.ComputeTriangulatedFaceVaryingPrimvar(
-          HdGetValueData(value), value.GetArraySize(), valueType, &value))
+          HdGetValueData(value), value.GetArraySize(), valueType, &value)
+#if PXR_VERSION >= 2511
+      != HdMeshComputationResult::Error
+#endif
+  )
   {
     return value;
   }

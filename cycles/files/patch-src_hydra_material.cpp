--- src/hydra/material.cpp.orig	2026-03-30 21:43:11 UTC
+++ src/hydra/material.cpp
@@ -11,6 +11,7 @@
 #include "scene/shader_graph.h"
 #include "scene/shader_nodes.h"
 
+#include <pxr/base/tf/stringUtils.h>
 #include <pxr/imaging/hd/sceneDelegate.h>
 
 HDCYCLES_NAMESPACE_OPEN_SCOPE
@@ -268,6 +269,15 @@ void HdCyclesMaterial::UpdateParameters(
                                         const SdfPath &nodePath)
 {
   for (const auto &param : parameters) {
+    // USD also passes the type of each input with a value (and its color
+    // space, if it has one) as the parameter "typeName:<input>"
+    // ("colorSpace:<input>"), which is not an input of the Cycles node.
+    if (TfStringStartsWith(param.first.GetString(), "typeName:") ||
+        TfStringStartsWith(param.first.GetString(), "colorSpace:"))
+    {
+      continue;
+    }
+
     VtValue value = param.second;
 
     // See if the parameter name is in USDPreviewSurface terms, and needs to be converted

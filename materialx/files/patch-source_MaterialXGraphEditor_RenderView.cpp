--- source/MaterialXGraphEditor/RenderView.cpp.orig	2026-02-18 17:23:39 UTC
+++ source/MaterialXGraphEditor/RenderView.cpp
@@ -16,6 +16,9 @@
 #include <MaterialXRender/TinyObjLoader.h>
 
 #include <MaterialXGenShader/DefaultColorManagementSystem.h>
+#ifdef MATERIALX_BUILD_OCIO
+#include <MaterialXGenShader/OcioColorManagementSystem.h>
+#endif
 
 #include <MaterialXFormat/Util.h>
 

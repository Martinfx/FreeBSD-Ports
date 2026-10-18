--- src/Layers/xrRender/r__dsgraph_render.cpp.orig	2026-10-01 00:00:00 UTC
+++ src/Layers/xrRender/r__dsgraph_render.cpp
@@ -28,12 +28,14 @@
 }
 
 // Sorting by SSA and changes minimizations
+// std::sort() requires a strict weak ordering: the original '>=' made two
+// passes with equal SSA compare less than each other, which lets libc++'s
+// unguarded partition run past the end of the range (and trap when libc++
+// hardening is enabled)
 template <typename T>
 bool cmp_pass(const T& left, const T& right)
 {
-    if (left->first->equal(*right->first))
-        return false;
-    return left->second.ssa >= right->second.ssa;
+    return left->second.ssa > right->second.ssa;
 }
 
 void R_dsgraph_structure::render_graph(u32 _priority)

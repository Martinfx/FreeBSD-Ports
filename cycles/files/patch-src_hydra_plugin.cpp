--- src/hydra/plugin.cpp.orig	2025-10-18 14:00:18 UTC
+++ src/hydra/plugin.cpp
@@ -44,6 +44,13 @@ bool HdCyclesPlugin::IsSupported() const
   return true;
 }
 #else
+#  if PXR_VERSION >= 2511
+bool HdCyclesPlugin::IsSupported(HdRendererCreateArgs const & /*rendererCreateArgs*/,
+                                 std::string * /*reasonWhyNot*/) const
+{
+  return true;
+}
+#  endif
 bool HdCyclesPlugin::IsSupported(bool /*gpuEnabled*/) const
 {
   return true;

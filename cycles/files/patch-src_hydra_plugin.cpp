--- src/hydra/plugin.cpp.orig	2026-03-30 21:43:11 UTC
+++ src/hydra/plugin.cpp
@@ -39,6 +39,13 @@ bool HdCyclesPlugin::IsSupported() const
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

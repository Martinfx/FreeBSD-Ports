--- src/hydra/plugin.h.orig	2026-03-30 21:43:11 UTC
+++ src/hydra/plugin.h
@@ -18,6 +18,10 @@ class HdCyclesPlugin final : public PXR_
 #if PXR_VERSION < 2302
   bool IsSupported() const override;
 #else
+#  if PXR_VERSION >= 2511
+  bool IsSupported(HdRendererCreateArgs const &rendererCreateArgs,
+                   std::string *reasonWhyNot = nullptr) const override;
+#  endif
   bool IsSupported(bool gpuEnabled) const override;
 #endif
 

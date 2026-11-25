--- src/third_party/blink/renderer/platform/graphics/begin_frame_provider.cc.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/blink/renderer/platform/graphics/begin_frame_provider.cc
@@ -75,7 +75,11 @@ void BeginFrameProvider::CreateComposito
 
   // Once we are using RAF, this thread is driving user interactive display
   // updates. Update priority accordingly.
+  // pledge(2)
+  // stop this baloney
+#if !defined(OS_OPENBSD)
   lease_.emplace(base::ThreadType::kPresentation);
+#endif
 
   mojo::Remote<mojom::blink::EmbeddedFrameSinkProvider> provider;
   Platform::Current()->GetBrowserInterfaceBroker()->GetInterface(

--- src/ui/compositor/compositor.cc.orig	2026-11-24 12:50:30 UTC
+++ src/ui/compositor/compositor.cc
@@ -976,7 +976,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   observer_list_.Notify(
       &CompositorObserver::OnCompositingCompleteSwapWithNewSize, this, size);

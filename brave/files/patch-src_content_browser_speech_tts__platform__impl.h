--- src/content/browser/speech/tts_platform_impl.h.orig	2026-11-24 12:50:30 UTC
+++ src/content/browser/speech/tts_platform_impl.h
@@ -15,7 +15,7 @@
 
 namespace content {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Overrides the library path captured when the Linux TTS singleton is created.
 // Must be called before TtsPlatform::GetInstance().
 CONTENT_EXPORT base::AutoReset<std::string>

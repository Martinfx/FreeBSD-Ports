--- src/chrome/services/speech/audio_source_fetcher_impl.cc.orig	2026-11-24 12:50:30 UTC
+++ src/chrome/services/speech/audio_source_fetcher_impl.cc
@@ -132,7 +132,7 @@ void AudioSourceFetcherImpl::Start(
 
   // TODO(crbug.com/40753481): Check implementation / sandbox policy on Mac and
   // Windows.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   is_started_ = true;
   // Initialize the AudioCapturerSource with |this| as the CaptureCallback,
   // get the parameters for the device ID, then start audio capture.

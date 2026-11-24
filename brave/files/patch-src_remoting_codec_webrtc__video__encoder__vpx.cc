--- src/remoting/codec/webrtc_video_encoder_vpx.cc.orig	2026-11-24 12:50:30 UTC
+++ src/remoting/codec/webrtc_video_encoder_vpx.cc
@@ -93,7 +93,7 @@ void SetVp8CodecParameters(vpx_codec_enc
                            const webrtc::DesktopSize& size) {
   SetCommonCodecParameters(config, size);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, using too many threads for VP8 encoding has been linked to high
   // CPU usage on machines that are under stress. See http://crbug.com/1151148.
   // 5/3/2022 update: Perf testing has shown that doubling the number of threads

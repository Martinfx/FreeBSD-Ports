--- media/base/media_switches.h.orig	2024-08-26 12:06:38 UTC
+++ media/base/media_switches.h
@@ -325,13 +325,25 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlatformHEVCEncoder
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPlaybackSpeedButton);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMediaEngagementData);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPreloadMetadataSuspend);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForCast);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kPulseaudioLoopbackForScreenShare);
+
+enum class AudioBackend {
+  kAuto,
+  kPulseAudio,
+  kSndio,
+  kAlsa
+};
+
+MEDIA_EXPORT BASE_DECLARE_FEATURE(kAudioBackend);
+MEDIA_EXPORT extern const base::FeatureParam<
+    AudioBackend>
+    kAudioBackendParam;
 #endif  // BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordMediaEngagementScores);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kRecordWebAudioEngagement);
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kReduceHardwareVideoDecoderBuffers);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kResumeBackgroundVideo);
@@ -346,7 +358,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUnifiedAutoplay);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseAndroidOverlayForSecureOnly);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseDecoderStreamForWebRTC);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseFakeDeviceForMediaStream);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoDecodeLinux);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoDecodeLinuxGL);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVideoEncodeLinux);
@@ -365,7 +377,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiH264TemporalLa
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp8TemporalLayerHWEncoding);
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVaapiVp9SModeHWEncoding);
 #endif  // defined(ARCH_CPU_X86_FAMILY) && BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kV4L2FlatStatefulVideoDecoder);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kVideoBlitColorAccuracy);
@@ -510,7 +522,7 @@ MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVide
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseGTFOOutOfProcessVideoDecoding);
 #endif  // BUILDFLAG(ALLOW_OOP_VIDEO_DECODER)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 MEDIA_EXPORT BASE_DECLARE_FEATURE(kUseOutOfProcessVideoEncoding);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 

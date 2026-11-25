--- src/third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc.orig	2026-11-24 12:50:30 UTC
+++ src/third_party/blink/renderer/modules/webaudio/audio_worklet_thread_test.cc
@@ -463,7 +463,7 @@ class AudioWorkletThreadPriorityTest
     // acquire SCHED_RR, so the thread remains in SCHED_NORMAL. However,
     // ChromeOS applies specific optimizations (Nice -10 and uclamp boost)
     // that are not present on standard Linux.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (expected_priority == base::ThreadType::kRealtimeAudio ||
         expected_priority == base::ThreadType::kPresentation) {
       EXPECT_EQ(actual_priority, base::ThreadType::kDefault);

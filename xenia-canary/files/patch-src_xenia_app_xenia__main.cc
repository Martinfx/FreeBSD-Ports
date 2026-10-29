--- src/xenia/app/xenia_main.cc.orig
+++ src/xenia/app/xenia_main.cc
@@ -36,9 +36,9 @@
 
 // Available audio systems:
 #include "xenia/apu/nop/nop_audio_system.h"
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX && !XE_PLATFORM_FREEBSD
 #include "xenia/apu/alsa/alsa_audio_system.h"
-#endif  // XE_PLATFORM_LINUX
+#endif  // XE_PLATFORM_LINUX && !XE_PLATFORM_FREEBSD
 #if !XE_PLATFORM_ANDROID
 #include "xenia/apu/sdl/sdl_audio_system.h"
 #endif  // !XE_PLATFORM_ANDROID
@@ -72,6 +72,10 @@
 #define APU_OPTIONS "[any, nop, sdl, xaudio2]"
 #define GPU_OPTIONS "[any, d3d12, vulkan, null]"
 #define HID_OPTIONS "[any, nop, sdl, keyboard, xinput]"
+#elif XE_PLATFORM_FREEBSD
+#define APU_OPTIONS "[any, nop, sdl]"
+#define GPU_OPTIONS "[any, vulkan, null]"
+#define HID_OPTIONS "[any, nop, sdl, keyboard]"
 #elif XE_PLATFORM_LINUX
 #define APU_OPTIONS "[any, alsa, nop, sdl]"
 #define GPU_OPTIONS "[any, vulkan, null]"
@@ -321,9 +325,9 @@ std::unique_ptr<apu::AudioSystem> EmulatorApp::CreateAudioSystem(
 #if XE_PLATFORM_WIN32
   factory.Add<apu::xaudio2::XAudio2AudioSystem>("xaudio2");
 #endif  // XE_PLATFORM_WIN32
-#if XE_PLATFORM_LINUX
+#if XE_PLATFORM_LINUX && !XE_PLATFORM_FREEBSD
   factory.Add<apu::alsa::ALSAAudioSystem>("alsa");
-#endif  // XE_PLATFORM_LINUX
+#endif  // XE_PLATFORM_LINUX && !XE_PLATFORM_FREEBSD
 #if !XE_PLATFORM_ANDROID
   factory.Add<apu::sdl::SDLAudioSystem>("sdl");
 #endif  // !XE_PLATFORM_ANDROID

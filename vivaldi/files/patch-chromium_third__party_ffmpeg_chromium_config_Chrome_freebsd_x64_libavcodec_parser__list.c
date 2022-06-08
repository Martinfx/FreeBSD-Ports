--- chromium/third_party/ffmpeg/chromium/config/Chrome/freebsd/x64/libavcodec/parser_list.c.orig	2022-06-07 19:27:09 UTC
+++ chromium/third_party/ffmpeg/chromium/config/Chrome/freebsd/x64/libavcodec/parser_list.c
@@ -0,0 +1,11 @@
+static const AVCodecParser * const parser_list[] = {
+    &ff_aac_parser,
+    &ff_flac_parser,
+    &ff_h264_parser,
+    &ff_mpegaudio_parser,
+    &ff_opus_parser,
+    &ff_vorbis_parser,
+    &ff_vp3_parser,
+    &ff_vp8_parser,
+    &ff_vp9_parser,
+    NULL };

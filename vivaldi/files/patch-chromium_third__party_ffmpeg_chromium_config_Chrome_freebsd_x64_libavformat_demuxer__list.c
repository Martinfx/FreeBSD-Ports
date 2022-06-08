--- chromium/third_party/ffmpeg/chromium/config/Chrome/freebsd/x64/libavformat/demuxer_list.c.orig	2022-06-07 19:27:43 UTC
+++ chromium/third_party/ffmpeg/chromium/config/Chrome/freebsd/x64/libavformat/demuxer_list.c
@@ -0,0 +1,9 @@
+static const AVInputFormat * const demuxer_list[] = {
+    &ff_aac_demuxer,
+    &ff_flac_demuxer,
+    &ff_matroska_demuxer,
+    &ff_mov_demuxer,
+    &ff_mp3_demuxer,
+    &ff_ogg_demuxer,
+    &ff_wav_demuxer,
+    NULL };

--- third_party/ffmpeg-xenia/config.h.orig
+++ third_party/ffmpeg-xenia/config.h
@@ -348,7 +348,11 @@
     #define HAVE_SYMVER 1
     #define HAVE_SYS_SOUNDCARD_H 1
     #define HAVE_GLOB 1
+    #ifndef __FreeBSD__
+    /* Only for subtitle charset conversion. On FreeBSD the iconv.h of GNU
+       libiconv in LOCALBASE would shadow the one of libc. */
     #define CONFIG_ICONV 1
+    #endif
   #endif
 #endif
 

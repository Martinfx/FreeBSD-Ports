--- src/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h.orig	2026-11-24 12:50:30 UTC
+++ src/v8/src/snapshot/embedded/platform-embedded-file-writer-base.h
@@ -37,6 +37,7 @@ enum class EmbeddedTargetOs {
   kWin,
   kStarboard,
   kZOS,
+  kOpenBSD,
   kGeneric,  // Everything not covered above falls in here.
 };
 

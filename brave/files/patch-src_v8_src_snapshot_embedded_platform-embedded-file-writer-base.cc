--- src/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc.orig	2026-11-24 12:50:30 UTC
+++ src/v8/src/snapshot/embedded/platform-embedded-file-writer-base.cc
@@ -150,6 +150,8 @@ EmbeddedTargetOs ToEmbeddedTargetOs(cons
     return EmbeddedTargetOs::kStarboard;
   } else if (string == "zos") {
     return EmbeddedTargetOs::kZOS;
+  } else if (string == "openbsd") {
+    return EmbeddedTargetOs::kOpenBSD;
   } else {
     return EmbeddedTargetOs::kGeneric;
   }

--- src/base/test/launcher/test_launcher.cc.orig	2026-11-24 12:50:30 UTC
+++ src/base/test/launcher/test_launcher.cc
@@ -67,6 +67,7 @@
 #include "third_party/abseil-cpp/absl/container/flat_hash_set.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"

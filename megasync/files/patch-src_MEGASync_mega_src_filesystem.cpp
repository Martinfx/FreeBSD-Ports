--- src/MEGASync/mega/src/filesystem.cpp.orig	2026-03-03 10:35:02 UTC
+++ src/MEGASync/mega/src/filesystem.cpp
@@ -28,7 +28,7 @@
 #include "mega/megaclient.h"
 #include "mega/node.h"
 #include "mega/sync.h"
-#include "megafs.h"
+#include "mega/posix/megafs.h"
 
 #include <cassert>
 #include <cctype>

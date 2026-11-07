--- core/DesktopEditor/fontengine/TextShaper.cpp.orig	2026-11-05 00:00:00 UTC
+++ core/DesktopEditor/fontengine/TextShaper.cpp
@@ -652,9 +652,9 @@
 
 #ifdef SUPPORT_HARFBUZZ_SHAPER
 
-#include <hb.h>
-#include <hb-ft.h>
-#include <hb-ot.h>
+#include <harfbuzz/hb.h>
+#include <harfbuzz/hb-ft.h>
+#include <harfbuzz/hb-ot.h>
 
 namespace NSShaper
 {

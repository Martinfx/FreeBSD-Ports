--- src/v8/src/objects/js-temporal-zoneinfo64.cc.orig	2026-11-24 12:50:30 UTC
+++ src/v8/src/objects/js-temporal-zoneinfo64.cc
@@ -18,7 +18,7 @@
 #ifdef V8_INTL_SUPPORT
 #ifndef V8_ENABLE_TEMPORAL_SYSTEMICU
 // ICU internal header file
-#include "udatamem.h"
+#include "../../third_party/icu/source/common/udatamem.h"
 #else
 /**
  * Shadow definition of UDataMemory

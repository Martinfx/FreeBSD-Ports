--- library/grt/src/diff/grtdiff.cpp.orig	2024-05-19 20:33:42 UTC
+++ library/grt/src/diff/grtdiff.cpp
@@ -23,7 +23,7 @@
 
 #include <assert.h>
 #include <algorithm>
-
+#include <sys/time.h>
 #include "base/util_functions.h"
 #include "base/log.h"
 

--- src/include/postgres.h.orig	2022-10-15 08:32:34 UTC
+++ src/include/postgres.h
@@ -50,6 +50,7 @@
 extern "C" {
 #endif
 
+#include <arpa/inet.h>
 #include "utils/elog.h"
 #include "utils/palloc.h"
 #include "storage/itemptr.h"

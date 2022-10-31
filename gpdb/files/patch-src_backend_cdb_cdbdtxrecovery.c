--- src/backend/cdb/cdbdtxrecovery.c.orig	2022-10-24 12:32:02 UTC
+++ src/backend/cdb/cdbdtxrecovery.c
@@ -12,6 +12,8 @@
 
 #include "postgres.h"
 #include <unistd.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 /* These are always necessary for a bgworker */
 #include "miscadmin.h"

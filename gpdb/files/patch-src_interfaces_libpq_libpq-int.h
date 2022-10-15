--- src/interfaces/libpq/libpq-int.h.orig	2022-10-05 17:37:13 UTC
+++ src/interfaces/libpq/libpq-int.h
@@ -22,7 +22,9 @@
 #define LIBPQ_INT_H
 
 /* We assume libpq-fe.h has already been included. */
+#include "libpq-fe.h"
 #include "c.h"
+#include "libpq-fe.h"
 #include "libpq-events.h"
 
 #include <time.h>

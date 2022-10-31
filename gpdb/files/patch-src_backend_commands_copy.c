--- src/backend/commands/copy.c.orig	2022-10-31 16:38:52 UTC
+++ src/backend/commands/copy.c
@@ -24,6 +24,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <catalog/catalog.h>
+#include <sys/wait.h>
 
 #include "access/heapam.h"
 #include "access/htup_details.h"

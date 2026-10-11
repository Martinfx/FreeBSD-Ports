--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/commons.h.orig	2026-02-24 00:10:13 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/commons.h
@@ -20,6 +20,7 @@
 #define COMMONS_H_
 
 #include <sys/types.h>
+#include <sys/endian.h>
 #include <sys/stat.h>
 #include <stdint.h>
 #include <stdlib.h>
@@ -41,7 +42,6 @@
 #include <map>
 #include <algorithm>
 
-#include "lib/primitives.h"
 #include "lib/Log.h"
 #include "NativeTask.h"
 
@@ -49,4 +49,12 @@
 
 #include "lib/Iterator.h"
 
+#ifdef __GNUC__
+#define likely(x)       __builtin_expect((x),1)
+#define unlikely(x)     __builtin_expect((x),0)
+#else
+#define likely(x)       (x)
+#define unlikely(x)     (x)
+#endif
+
 #endif /* COMMONS_H_ */

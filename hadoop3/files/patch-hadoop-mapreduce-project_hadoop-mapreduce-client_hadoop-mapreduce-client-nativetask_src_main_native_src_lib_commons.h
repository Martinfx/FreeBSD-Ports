--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/commons.h.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/commons.h
@@ -41,7 +41,6 @@
 #include <map>
 #include <algorithm>
 
-#include "lib/primitives.h"
 #include "lib/Log.h"
 #include "NativeTask.h"
 
@@ -49,4 +48,12 @@
 
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

--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestMemBlockIterator.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestMemBlockIterator.cc
@@ -59,7 +59,7 @@ class MemoryBlockFactory {
       kv->keyLength = 4;
       kv->valueLength = 4;
       uint32_t * key = (uint32_t *)kv->getKey();
-      *key = bswap(index);
+      *key = bswap32(index);
     }
     return block1;
   }

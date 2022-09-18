--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestMemoryBlock.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestMemoryBlock.cc
@@ -85,17 +85,17 @@ TEST(MemoryBlock, sort) {
   medium->keyLength = 4;
   medium->valueLength = 4;
   uint32_t * mediumKey = (uint32_t *)medium->getKey();
-  *mediumKey = bswap(MEDIUM);
+  *mediumKey = bswap32(MEDIUM);
 
   small->keyLength = 4;
   small->valueLength = 4;
   uint32_t * smallKey = (uint32_t *)small->getKey();
-  *smallKey = bswap(SMALL);
+  *smallKey = bswap32(SMALL);
 
   big->keyLength = 4;
   big->valueLength = 4;
   uint32_t * bigKey = (uint32_t *)big->getKey();
-  *bigKey = bswap(BIG);
+  *bigKey = bswap32(BIG);
 
   ComparatorPtr bytesComparator = NativeTask::get_comparator(BytesType, NULL);
   block.sort(CPPSORT, bytesComparator);

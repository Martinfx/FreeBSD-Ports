--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestIFile.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestIFile.cc
@@ -190,7 +190,7 @@ TEST(IFile, TestGlibCBug) {
   reader->nextPartition();
   uint32_t index = 0;
   while (NULL != (key = reader->nextKey(length))) {
-    int32_t realKey = (int32_t)bswap(*(uint32_t *)(key));
+    int32_t realKey = (int32_t)bswap32(*(uint32_t *)(key));
     ASSERT_LT(index, 5);
     ASSERT_EQ(expect[index], realKey);
     index++;

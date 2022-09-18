--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestKVBuffer.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestKVBuffer.cc
@@ -43,8 +43,8 @@ TEST(KVBuffer, test) {
   ASSERT_EQ(8, kv1->getKey() - buff);
   ASSERT_EQ(strlen(KEY) + 8, kv1->getValue() - buff);
 
-  kv1->keyLength = bswap(kv1->keyLength);
-  kv1->valueLength = bswap(kv1->valueLength);
+  kv1->keyLength = bswap32(kv1->keyLength);
+  kv1->valueLength = bswap32(kv1->valueLength);
 
   ASSERT_EQ(8, kv1->headerLength());
   ASSERT_EQ(strlen(KEY) + strlen(VALUE) + 8, kv1->lengthConvertEndium());

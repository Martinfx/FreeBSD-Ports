--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestPartitionBucket.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/lib/TestPartitionBucket.cc
@@ -129,15 +129,15 @@ TEST(PartitionBucket, sort) {
   const uint32_t BIG = 1000;
 
   kv1->keyLength = 4;
-  *((uint32_t *)kv1->getKey()) = bswap(BIG);
+  *((uint32_t *)kv1->getKey()) = bswap32(BIG);
   kv1->valueLength = KV_SIZE - kv1->headerLength() - kv1->keyLength;
 
   kv2->keyLength = 4;
-  *((uint32_t *)kv2->getKey()) = bswap(SMALL);
+  *((uint32_t *)kv2->getKey()) = bswap32(SMALL);
   kv2->valueLength = KV_SIZE - kv2->headerLength() - kv2->keyLength;
 
   kv3->keyLength = 4;
-  *((uint32_t *)kv3->getKey()) = bswap(MEDIUM);
+  *((uint32_t *)kv3->getKey()) = bswap32(MEDIUM);
   kv3->valueLength = KV_SIZE - kv3->headerLength() - kv3->keyLength;
 
   bucket->sort(DUALPIVOTSORT);
@@ -148,13 +148,13 @@ TEST(PartitionBucket, sort) {
   Buffer value;
   iter->next(key, value);
 
-  ASSERT_EQ(SMALL, bswap(*(uint32_t * )key.data()));
+  ASSERT_EQ(SMALL, bswap32(*(uint32_t * )key.data()));
 
   iter->next(key, value);
-  ASSERT_EQ(MEDIUM, bswap(*(uint32_t * )key.data()));
+  ASSERT_EQ(MEDIUM, bswap32(*(uint32_t * )key.data()));
 
   iter->next(key, value);
-  ASSERT_EQ(BIG, bswap(*(uint32_t * )key.data()));
+  ASSERT_EQ(BIG, bswap32(*(uint32_t * )key.data()));
 
   delete iter;
   delete bucket;
@@ -181,15 +181,15 @@ TEST(PartitionBucket, spill) {
   const uint32_t BIG = 1000;
 
   kv1->keyLength = 4;
-  *((uint32_t *)kv1->getKey()) = bswap(BIG);
+  *((uint32_t *)kv1->getKey()) = bswap32(BIG);
   kv1->valueLength = KV_SIZE - KVBuffer::headerLength() - kv1->keyLength;
 
   kv2->keyLength = 4;
-  *((uint32_t *)kv2->getKey()) = bswap(SMALL);
+  *((uint32_t *)kv2->getKey()) = bswap32(SMALL);
   kv2->valueLength = KV_SIZE - KVBuffer::headerLength() - kv2->keyLength;
 
   kv3->keyLength = 4;
-  *((uint32_t *)kv3->getKey()) = bswap(MEDIUM);
+  *((uint32_t *)kv3->getKey()) = bswap32(MEDIUM);
   kv3->valueLength = KV_SIZE - KVBuffer::headerLength() - kv3->keyLength;
 
   bucket->sort(DUALPIVOTSORT);
@@ -203,17 +203,17 @@ TEST(PartitionBucket, spill) {
   KVBuffer * first = (KVBuffer *)writer.buff();
   ASSERT_EQ(4, first->keyLength);
   ASSERT_EQ(KV_SIZE - KVBuffer::headerLength() - 4, first->valueLength);
-  ASSERT_EQ(bswap(SMALL), (*(uint32_t * )(first->getKey())));
+  ASSERT_EQ(bswap32(SMALL), (*(uint32_t * )(first->getKey())));
 
   KVBuffer * second = first->next();
   ASSERT_EQ(4, second->keyLength);
   ASSERT_EQ(KV_SIZE - KVBuffer::headerLength() - 4, second->valueLength);
-  ASSERT_EQ(bswap(MEDIUM), (*(uint32_t * )(second->getKey())));
+  ASSERT_EQ(bswap32(MEDIUM), (*(uint32_t * )(second->getKey())));
 
   KVBuffer * third = second->next();
   ASSERT_EQ(4, third->keyLength);
   ASSERT_EQ(KV_SIZE - KVBuffer::headerLength() - 4, third->valueLength);
-  ASSERT_EQ(bswap(BIG), (*(uint32_t * )(third->getKey())));
+  ASSERT_EQ(bswap32(BIG), (*(uint32_t * )(third->getKey())));
 
   delete [] buff;
   delete bucket;

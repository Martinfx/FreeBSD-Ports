--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestSort.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestSort.cc
@@ -121,7 +121,7 @@ static int compare_offset2(const void * plh, const voi
   KVBuffer * rhb = (KVBuffer*)get_position(*(uint32_t*)prh);
 
   uint32_t minlen = std::min(lhb->keyLength, rhb->keyLength);
-  int64_t ret = fmemcmp(lhb->content, rhb->content, minlen);
+  int64_t ret = memcmp(lhb->content, rhb->content, minlen);
   if (ret) {
     return ret;
   }
@@ -139,7 +139,7 @@ class CompareOffset2 {
     KVBuffer * rhb = (KVBuffer*)get_position(rhs);
 
     uint32_t minlen = std::min(lhb->keyLength, rhb->keyLength);
-    int64_t ret = fmemcmp(lhb->content, rhb->content, minlen);
+    int64_t ret = memcmp(lhb->content, rhb->content, minlen);
     if (ret) {
       return ret;
     }
@@ -158,7 +158,7 @@ class OffsetLessThan2 {
     KVBuffer * rhb = (KVBuffer*)get_position(rhs);
 
     uint32_t minlen = std::min(lhb->keyLength, rhb->keyLength);
-    int64_t ret = fmemcmp(lhb->content, rhb->content, minlen);
+    int64_t ret = memcmp(lhb->content, rhb->content, minlen);
     return ret < 0 || (ret == 0 && (lhb->keyLength < rhb->keyLength));
   }
 };

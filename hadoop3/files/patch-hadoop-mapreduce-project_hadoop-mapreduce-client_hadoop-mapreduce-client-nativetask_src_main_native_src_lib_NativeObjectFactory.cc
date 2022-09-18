--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/NativeObjectFactory.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/lib/NativeObjectFactory.cc
@@ -299,7 +299,7 @@ int NativeObjectFactory::BytesComparator(const char * 
     uint32_t destLength) {
 
   uint32_t minlen = std::min(srcLength, destLength);
-  int64_t ret = fmemcmp(src, dest, minlen);
+  int64_t ret = memcmp(src, dest, minlen);
   if (ret > 0) {
     return 1;
   } else if (ret < 0) {
@@ -317,8 +317,8 @@ int NativeObjectFactory::IntComparator(const char * sr
     uint32_t destLength) {
   int result = (*src) - (*dest);
   if (result == 0) {
-    uint32_t from = bswap(*(uint32_t*)src);
-    uint32_t to = bswap(*(uint32_t*)dest);
+    uint32_t from = bswap32(*(uint32_t*)src);
+    uint32_t to = bswap32(*(uint32_t*)dest);
     if (from > to) {
       return 1;
     } else if (from == to) {
@@ -380,8 +380,8 @@ int NativeObjectFactory::FloatComparator(const char * 
     THROW_EXCEPTION_EX(IOException, "float comparator, while src/dest lengt is not 4");
   }
 
-  uint32_t from = bswap(*(uint32_t*)src);
-  uint32_t to = bswap(*(uint32_t*)dest);
+  uint32_t from = bswap32(*(uint32_t*)src);
+  uint32_t to = bswap32(*(uint32_t*)dest);
 
   float * srcValue = (float *)(&from);
   float * destValue = (float *)(&to);

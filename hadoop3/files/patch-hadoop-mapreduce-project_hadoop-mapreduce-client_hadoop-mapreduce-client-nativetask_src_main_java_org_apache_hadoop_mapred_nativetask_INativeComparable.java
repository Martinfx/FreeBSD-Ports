--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/java/org/apache/hadoop/mapred/nativetask/INativeComparable.java.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/java/org/apache/hadoop/mapred/nativetask/INativeComparable.java
@@ -42,8 +42,8 @@ import org.apache.hadoop.classification.InterfaceStabi
  * <code>
  *   int HivePlatform::HiveKeyComparator(const char * src, uint32_t srcLength,
  *   const char * dest, uint32_t destLength) {
- *     uint32_t sl = bswap(*(uint32_t*)src);
- *     uint32_t dl = bswap(*(uint32_t*)dest);
+ *     uint32_t sl = bswap32(*(uint32_t*)src);
+ *     uint32_t dl = bswap32(*(uint32_t*)dest);
  *     return NativeObjectFactory::BytesComparator(src + 4, sl, dest + 4, dl);
  *   }
  * </code>

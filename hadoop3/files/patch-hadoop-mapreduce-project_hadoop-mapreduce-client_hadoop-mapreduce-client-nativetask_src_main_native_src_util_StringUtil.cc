--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/util/StringUtil.cc.orig	2019-04-21 10:28:49 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/src/util/StringUtil.cc
@@ -36,19 +36,19 @@ string StringUtil::ToString(uint32_t v) {
 
 string StringUtil::ToString(int64_t v) {
   char tmp[32];
-  snprintf(tmp, 32, "%"PRId64, v);
+  snprintf(tmp, 32, "%" PRId64, v);
   return tmp;
 }
 
 string StringUtil::ToString(int64_t v, char pad, int64_t len) {
   char tmp[32];
-  snprintf(tmp, 32, "%%%c%"PRId64""PRId64, pad, len);
+  snprintf(tmp, 32, "%%%c%" PRId64"" PRId64, pad, len);
   return Format(tmp, v);
 }
 
 string StringUtil::ToString(uint64_t v) {
   char tmp[32];
-  snprintf(tmp, 32, "%"PRIu64, v);
+  snprintf(tmp, 32, "%" PRIu64, v);
   return tmp;
 }
 

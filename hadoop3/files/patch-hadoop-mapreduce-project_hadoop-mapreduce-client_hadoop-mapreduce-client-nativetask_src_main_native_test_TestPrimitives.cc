--- hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestPrimitives.cc.orig	2018-10-18 18:38:39 UTC
+++ hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-nativetask/src/main/native/test/TestPrimitives.cc
@@ -18,98 +18,7 @@
 
 #include "test_commons.h"
 
-TEST(Primitives, fmemcmp) {
-  std::vector<std::string> vs;
-  char buff[14];
-  vs.push_back("");
-  for (uint32_t i = 0; i < 5000; i += 7) {
-    snprintf(buff, 14, "%d", i * 31);
-    vs.push_back(buff);
-    snprintf(buff, 10, "%010d", i);
-    vs.push_back(buff);
-  }
-  for (size_t i = 0; i < vs.size(); i++) {
-    for (size_t j = 0; j < vs.size(); j++) {
-      std::string & ls = vs[i];
-      std::string & rs = vs[j];
-      size_t m = std::min(ls.length(), rs.length());
-      int c = memcmp(ls.c_str(), rs.c_str(), m);
-      int t = fmemcmp(ls.c_str(), rs.c_str(), m);
-      if (!((c == 0 && t == 0) || (c > 0 && t > 0) || (c < 0 && t < 0))) {
-        ASSERT_TRUE(false);
-      }
-    }
-  }
-}
-
-static int test_memcmp() {
-  uint8_t buff[2048];
-  for (uint32_t i = 0; i < 2048; i++) {
-    buff[i] = i & 0xff;
-  }
-  std::random_shuffle(buff, buff + 2048);
-  int r = 0;
-  for (uint32_t i = 0; i < 100000000; i++) {
-    int offset = i % 1000;
-    r += memcmp(buff, buff + 1024, 5);
-    r += memcmp(buff + offset, buff + 1124, 9);
-    r += memcmp(buff + offset, buff + 1224, 10);
-    r += memcmp(buff + offset, buff + 1324, 15);
-    r += memcmp(buff + offset, buff + 1424, 16);
-    r += memcmp(buff + offset, buff + 1524, 17);
-    r += memcmp(buff + offset, buff + 1624, 18);
-    r += memcmp(buff + offset, buff + 1724, 19);
-  }
-  return r;
-}
-
-static int test_fmemcmp() {
-  char buff[2048];
-  for (uint32_t i = 0; i < 2048; i++) {
-    buff[i] = i & 0xff;
-  }
-  std::random_shuffle(buff, buff + 2048);
-  int r = 0;
-  for (uint32_t i = 0; i < 100000000; i++) {
-    int offset = i % 1000;
-    r += fmemcmp(buff, buff + 1024, 5);
-    r += fmemcmp(buff + offset, buff + 1124, 9);
-    r += fmemcmp(buff + offset, buff + 1224, 10);
-    r += fmemcmp(buff + offset, buff + 1324, 15);
-    r += fmemcmp(buff + offset, buff + 1424, 16);
-    r += fmemcmp(buff + offset, buff + 1524, 17);
-    r += fmemcmp(buff + offset, buff + 1624, 18);
-    r += fmemcmp(buff + offset, buff + 1724, 19);
-  }
-  return r;
-}
-
-TEST(Perf, fmemcmp) {
-  Timer t;
-  int a = test_memcmp();
-  LOG("%s", t.getInterval(" memcmp ").c_str());
-  t.reset();
-  int b = test_fmemcmp();
-  LOG("%s", t.getInterval(" fmemcmp ").c_str());
-  // prevent compiler optimization
-  TestConfig.setInt("tempvalue", a + b);
-}
-
-static void test_memcpy_perf_len(char * src, char * dest, size_t len, size_t time) {
-  for (size_t i = 0; i < time; i++) {
-    memcpy(src, dest, len);
-    memcpy(dest, src, len);
-  }
-}
-
-static void test_simple_memcpy_perf_len(char * src, char * dest, size_t len, size_t time) {
-  for (size_t i = 0; i < time; i++) {
-    simple_memcpy(src, dest, len);
-    simple_memcpy(dest, src, len);
-  }
-}
-
-TEST(Perf, simple_memcpy_small) {
+TEST(Perf, memcpy_small) {
   char * src = new char[10240];
   char * dest = new char[10240];
   char buff[32];
@@ -117,11 +26,10 @@ TEST(Perf, simple_memcpy_small) {
     LOG("------------------------------");
     snprintf(buff, 32, "       memcpy %luB\t", len);
     Timer t;
-    test_memcpy_perf_len(src, dest, len, 1000000);
-    LOG("%s", t.getInterval(buff).c_str());
-    snprintf(buff, 32, "simple_memcpy %luB\t", len);
-    t.reset();
-    test_simple_memcpy_perf_len(src, dest, len, 1000000);
+    for (size_t i = 0; i < 1000000; i++) {
+      memcpy(src, dest, len);
+      memcpy(dest, src, len);
+    }
     LOG("%s", t.getInterval(buff).c_str());
   }
   delete[] src;
@@ -293,11 +201,6 @@ TEST(Perf, memcpy_batch) {
     memcpy(dest, src, size);
   }
   LOG("%s", t.getSpeedM("memcpy", mb).c_str());
-  t.reset();
-  for (size_t i = 0; i < mb; i += size) {
-    simple_memcpy(dest, src, size);
-  }
-  LOG("%s", t.getSpeedM("simple_memcpy", mb).c_str());
   delete[] src;
   delete[] dest;
 }

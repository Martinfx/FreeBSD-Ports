--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/third_party/tr2/optional.hpp.orig	2026-02-24 00:10:13 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/third_party/tr2/optional.hpp
@@ -202,7 +202,12 @@
 # define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) ((CHECK) ? (EXPR) : (fail(#CHECK, __FILE__, __LINE__), (EXPR)))
   inline void fail(const char* expr, const char* file, int line)
   {
+#if defined __FreeBSD__
+    // FreeBSD's __assert() is (func, file, line, failedexpr).
+    __assert("", file, line, expr);
+#else
     __assert(expr, file, line);
+#endif
   }
 #elif defined __GNUC__
 # define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) ((CHECK) ? (EXPR) : (fail(#CHECK, __FILE__, __LINE__), (EXPR)))

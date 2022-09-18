--- hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/third_party/tr2/optional.hpp.orig	2019-04-21 09:03:51 UTC
+++ hadoop-hdfs-project/hadoop-hdfs-native-client/src/main/native/libhdfspp/third_party/tr2/optional.hpp
@@ -199,10 +199,10 @@ template <class T> inline constexpr typename std::remo
 #if defined NDEBUG
 # define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) (EXPR)
 #elif defined __clang__ || defined __GNU_LIBRARY__
-# define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) ((CHECK) ? (EXPR) : (fail(#CHECK, __FILE__, __LINE__), (EXPR)))
-  inline void fail(const char* expr, const char* file, int line)
+# define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) ((CHECK) ? (EXPR) : (fail(#CHECK, __FILE__, __func__, __LINE__), (EXPR)))
+  inline void fail(const char* expr, const char* file, const char* func, int line)
   {
-    __assert(expr, file, line);
+    __assert(file, func, line, expr);
   }
 #elif defined __GNUC__
 # define TR2_OPTIONAL_ASSERTED_EXPRESSION(CHECK, EXPR) ((CHECK) ? (EXPR) : (fail(#CHECK, __FILE__, __LINE__), (EXPR)))

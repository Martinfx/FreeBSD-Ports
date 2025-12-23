--- src/core/smartPointers/ememory.h.orig	2025-08-06 11:39:26 UTC
+++ src/core/smartPointers/ememory.h
@@ -36,7 +36,7 @@
     template <bool T> using BoolConstant = std::bool_constant<T>;
 #elif defined(Q_OS_LINUX)
     template <bool T> using BoolConstant = std::__bool_constant<T>;
-#elif (defined (Q_OS_MAC))
+#elif (defined (Q_OS_MAC)) || defined(Q_OS_FREEBSD)
     template <bool T> using BoolConstant = std::integral_constant<bool, T>;
 #endif
 

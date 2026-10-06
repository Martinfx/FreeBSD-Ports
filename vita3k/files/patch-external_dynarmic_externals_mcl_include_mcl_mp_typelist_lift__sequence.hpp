--- external/dynarmic/externals/mcl/include/mcl/mp/typelist/lift_sequence.hpp.orig	2026-10-06 04:22:04 UTC
+++ external/dynarmic/externals/mcl/include/mcl/mp/typelist/lift_sequence.hpp
@@ -5,6 +5,7 @@
 #pragma once
 
 #include <type_traits>
+#include <utility>
 
 #include "mcl/mp/typelist/list.hpp"
 
@@ -15,8 +16,10 @@ namespace detail {
 template<class VL>
 struct lift_sequence_impl;
 
-template<class T, template<class, T...> class VLT, T... values>
-struct lift_sequence_impl<VLT<T, values...>> {
+// Clang >= 19 (P0522R0 enabled by default) no longer matches std::integer_sequence
+// against a template<class, T...> template template parameter.
+template<class T, T... values>
+struct lift_sequence_impl<std::integer_sequence<T, values...>> {
     using type = list<std::integral_constant<T, values>...>;
 };
 

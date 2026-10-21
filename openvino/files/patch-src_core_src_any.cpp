--- src/core/src/any.cpp.orig	2026-10-17 22:40:00 UTC
+++ src/core/src/any.cpp
@@ -27,7 +27,7 @@
 
 bool util::equal(std::type_index lhs, std::type_index rhs) {
     auto result = lhs == rhs;
-#if (defined(__ANDROID__) || defined(__APPLE__) || defined(__CHROMIUMOS__)) && defined(__clang__)
+#if (defined(__ANDROID__) || defined(__APPLE__) || defined(__CHROMIUMOS__) || defined(__FreeBSD__)) && defined(__clang__)
     if (!result) {
         result = std::strcmp(lhs.name(), rhs.name()) == 0;
     }

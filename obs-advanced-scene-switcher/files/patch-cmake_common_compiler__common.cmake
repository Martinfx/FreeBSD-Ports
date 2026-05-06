--- cmake/common/compiler_common.cmake.orig	2026-01-09 01:58:28 UTC
+++ cmake/common/compiler_common.cmake
@@ -27,7 +27,6 @@ set(_obs_clang_c_options
     -Wdeprecated-declarations
     -Wempty-body
     -Wenum-conversion
-    -Werror=return-type
     -Wextra
     -Wformat
     -Wformat-security

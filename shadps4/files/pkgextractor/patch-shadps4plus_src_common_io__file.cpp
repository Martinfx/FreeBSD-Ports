--- shadps4plus/src/common/io_file.cpp.orig	2026-01-22 18:54:16 UTC
+++ shadps4plus/src/common/io_file.cpp
@@ -379,7 +379,7 @@
 
     errno = 0;
 
-    const auto seek_result = fseeko64(file, offset, ToSeekOrigin(origin)) == 0;
+    const auto seek_result = fseeko(file, offset, ToSeekOrigin(origin)) == 0;
 
     if (!seek_result) {
         const auto ec = std::error_code{errno, std::generic_category()};

--- externals/hwinfo/src/linux/disk.cpp.orig	2025-09-25 06:26:01 UTC
+++ externals/hwinfo/src/linux/disk.cpp
@@ -13,6 +13,8 @@
 #include <fstream>
 #include <regex>
 #include <vector>
+#include <sstream>
+
 
 namespace {
 

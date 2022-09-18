--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/test/test_configuration.cc.orig	2018-10-18 18:38:40 UTC
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/native/container-executor/test/test_configuration.cc
@@ -18,6 +18,7 @@
 
 #include <gtest/gtest.h>
 #include <fstream>
+#include <istream>
 
 extern "C" {
 #include "util.h"

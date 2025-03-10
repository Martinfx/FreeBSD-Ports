--- src/IECore/PathVectorParameter.cpp.orig	2024-11-26 17:11:55 UTC
+++ src/IECore/PathVectorParameter.cpp
@@ -38,8 +38,8 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
 #include "boost/filesystem/operations.hpp"
+#include "boost/filesystem/path.hpp"
 
 #include <algorithm>
 

--- src/IECore/PathParameter.cpp.orig	2024-11-26 17:10:29 UTC
+++ src/IECore/PathParameter.cpp
@@ -38,7 +38,7 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/filesystem/operations.hpp"
 
 #include <algorithm>

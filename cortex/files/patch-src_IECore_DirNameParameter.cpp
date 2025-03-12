--- src/IECore/DirNameParameter.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/DirNameParameter.cpp
@@ -38,7 +38,7 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/filesystem/operations.hpp"
 
 #include <algorithm>

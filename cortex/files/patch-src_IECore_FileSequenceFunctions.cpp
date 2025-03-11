--- src/IECore/FileSequenceFunctions.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/FileSequenceFunctions.cpp
@@ -42,7 +42,7 @@
 #include "IECore/ReversedFrameList.h"
 
 #include "boost/algorithm/string.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/directory.hpp"
 #include "boost/filesystem/operations.hpp"
 #include "boost/filesystem/path.hpp"
 #include "boost/format.hpp"

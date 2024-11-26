--- src/IECore/FileSequenceFunctions.cpp.orig	2024-11-26 16:53:32 UTC
+++ src/IECore/FileSequenceFunctions.cpp
@@ -42,9 +42,9 @@
 #include "IECore/ReversedFrameList.h"
 
 #include "boost/algorithm/string.hpp"
-#include "boost/filesystem/convenience.hpp"
 #include "boost/filesystem/operations.hpp"
 #include "boost/filesystem/path.hpp"
+#include "boost/filesystem/directory.hpp"
 #include "boost/format.hpp"
 #include "boost/lexical_cast.hpp"
 #include "boost/regex.hpp"

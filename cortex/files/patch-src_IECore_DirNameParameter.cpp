--- src/IECore/DirNameParameter.cpp.orig	2024-11-20 16:12:36 UTC
+++ src/IECore/DirNameParameter.cpp
@@ -1,3 +1,4 @@
+
 //////////////////////////////////////////////////////////////////////////
 //
 //  Copyright (c) 2007-2010, Image Engine Design Inc. All rights reserved.
@@ -38,9 +39,8 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
 #include "boost/filesystem/operations.hpp"
-
+#include "boost/filesystem/path.hpp"
 #include <algorithm>
 
 using namespace boost;

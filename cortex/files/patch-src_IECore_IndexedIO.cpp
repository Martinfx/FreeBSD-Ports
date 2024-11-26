--- src/IECore/IndexedIO.cpp.orig	2024-11-26 17:06:28 UTC
+++ src/IECore/IndexedIO.cpp
@@ -33,14 +33,12 @@
 //////////////////////////////////////////////////////////////////////////
 
 #include "IECore/IndexedIO.h"
-
 #include "IECore/Exception.h"
 
-#include "boost/filesystem/convenience.hpp"
 #include "boost/algorithm/string.hpp"
+#include "boost/filesystem/path.hpp"
 
 #include <iostream>
-
 #include <math.h>
 
 using namespace IECore;
@@ -76,7 +74,7 @@ IndexedIOPtr IndexedIO::create( const std::string &pat
 {
 	IndexedIOPtr result = nullptr;
 
-	std::string extension = fs::extension(path);
+	std::string extension = fs::path(path).extension().string();
 	boost::to_lower( extension );
 
 	const CreatorMap &createFns = creators();

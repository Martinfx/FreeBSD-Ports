--- src/IECore/IndexedIO.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/IndexedIO.cpp
@@ -36,7 +36,7 @@
 
 #include "IECore/Exception.h"
 
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/algorithm/string.hpp"
 
 #include <iostream>
@@ -76,7 +76,7 @@ IndexedIOPtr IndexedIO::create( const std::string &pat
 {
 	IndexedIOPtr result = nullptr;
 
-	std::string extension = fs::extension(path);
+	std::string extension = fs::path(path).extension().string();
 	boost::to_lower( extension );
 
 	const CreatorMap &createFns = creators();

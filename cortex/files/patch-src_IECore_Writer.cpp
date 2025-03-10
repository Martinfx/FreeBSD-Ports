--- src/IECore/Writer.cpp.orig	2024-11-26 17:28:31 UTC
+++ src/IECore/Writer.cpp
@@ -41,7 +41,7 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 
 #include <cassert>
 
@@ -116,7 +116,7 @@ WriterPtr Writer::create( ObjectPtr object, const std:
 
 WriterPtr Writer::create( ObjectPtr object, const std::string &fileName )
 {
-	string ext = extension(boost::filesystem::path(fileName));
+	string ext = path(boost::filesystem::path(fileName)).extension().string();
 
 	ExtensionsToFnsMap *m = extensionsToFns();
 	assert( m );
@@ -146,7 +146,7 @@ WriterPtr Writer::create( const std::string &fileName 
 
 WriterPtr Writer::create( const std::string &fileName )
 {
-	string ext = extension(boost::filesystem::path(fileName));
+	string ext = path(boost::filesystem::path(fileName)).extension().string();
 
 	ExtensionsToFnsMap *m = extensionsToFns();
 	ExtensionsToFnsMap::const_iterator it = m->find( ext );

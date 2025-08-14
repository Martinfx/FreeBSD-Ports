--- src/IECore/Reader.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/Reader.cpp
@@ -40,7 +40,7 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 
 using namespace std;
 using namespace IECore;
@@ -84,7 +84,7 @@ ReaderPtr Reader::create( const std::string &fileName 
 	bool knownExtension = false;
 	ExtensionsToFnsMap *m = extensionsToFns();
 	assert( m );
-	string ext = extension(boost::filesystem::path(fileName));
+	string ext = path(boost::filesystem::path(fileName)).extension().string();
 	if( ext!="" )
 	{
 		ExtensionsToFnsMap::const_iterator it = m->find( ext );

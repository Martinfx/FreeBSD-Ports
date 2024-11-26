--- src/IECore/FileNameParameter.cpp.orig	2024-11-20 16:12:36 UTC
+++ src/IECore/FileNameParameter.cpp
@@ -39,8 +39,8 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
 #include "boost/filesystem/operations.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/format.hpp"
 
 #include <algorithm>
@@ -87,8 +87,8 @@ bool FileNameParameter::valueValid( const Object *valu
 	// extensions check
 	if( extensions().size() )
 	{
-		string ext = boost::filesystem::extension(boost::filesystem::path( s->readable()));
-
+		//string ext = boost::filesystem::extension(boost::filesystem::path( s->readable()));
+		string ext = boost::filesystem::path(boost::filesystem::path( s->readable())).extension().string();
 		const vector<string> &exts = extensions();
 		bool found = false;
 		for( vector<string>::const_iterator it=exts.begin(); it!=exts.end(); it++ )

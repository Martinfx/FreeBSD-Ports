--- src/IECore/FileNameParameter.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECore/FileNameParameter.cpp
@@ -39,7 +39,7 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/filesystem/operations.hpp"
 #include "boost/format.hpp"
 
@@ -87,7 +87,7 @@ bool FileNameParameter::valueValid( const Object *valu
 	// extensions check
 	if( extensions().size() )
 	{
-		string ext = boost::filesystem::extension(boost::filesystem::path( s->readable()));
+		string ext = boost::filesystem::path(boost::filesystem::path( s->readable())).extension().string();
 
 		const vector<string> &exts = extensions();
 		bool found = false;

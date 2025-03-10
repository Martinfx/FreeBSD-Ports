--- src/IECore/FileSequenceParameter.cpp.orig	2024-11-26 16:56:11 UTC
+++ src/IECore/FileSequenceParameter.cpp
@@ -41,7 +41,8 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/operations.hpp"
+#include "boost/filesystem/path.hpp"
 
 #include <algorithm>
 #include <cassert>
@@ -130,7 +131,9 @@ bool FileSequenceParameter::valueValid( const Object *
 
 	if ( m_extensions.size() )
 	{
-		std::string ext = boost::filesystem::extension( boost::filesystem::path( fileSequence->getFileName() ) );
+		//std::string ext = boost::filesystem::extension( boost::filesystem::path( fileSequence->getFileName() ) );
+		std::string ext = boost::filesystem::path( boost::filesystem::path( fileSequence->getFileName() ) ).extension().string();
+
 		if ( ext.size() && ext[0] == '.' )
 		{
 			ext = ext.substr( 1, ext.size() - 1 );

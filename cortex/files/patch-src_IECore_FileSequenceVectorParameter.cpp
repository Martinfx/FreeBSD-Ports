--- src/IECore/FileSequenceVectorParameter.cpp.orig	2024-11-26 17:03:49 UTC
+++ src/IECore/FileSequenceVectorParameter.cpp
@@ -41,7 +41,8 @@
 
 #include "boost/algorithm/string/classification.hpp"
 #include "boost/algorithm/string/split.hpp"
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/operations.hpp"
+#include "boost/filesystem/path.hpp"
 
 #include <algorithm>
 #include <cassert>
@@ -131,7 +132,7 @@ bool FileSequenceVectorParameter::valueValid( const Ob
 
 		if ( m_extensions.size() )
 		{
-			std::string ext = boost::filesystem::extension( boost::filesystem::path( fileSequence->getFileName() ) );
+			std::string ext = boost::filesystem::path( boost::filesystem::path( fileSequence->getFileName() ) ).extension().string();
 			if ( ext.size() && ext[0] == '.' )
 			{
 				ext = ext.substr( 1, ext.size() - 1 );

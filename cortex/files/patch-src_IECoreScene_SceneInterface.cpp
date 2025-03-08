--- src/IECoreScene/SceneInterface.cpp.orig	2024-11-29 15:48:55 UTC
+++ src/IECoreScene/SceneInterface.cpp
@@ -33,10 +33,9 @@
 //////////////////////////////////////////////////////////////////////////
 
 #include "IECoreScene/SceneInterface.h"
-
-#include "boost/filesystem/convenience.hpp"
 #include "boost/tokenizer.hpp"
 #include "boost/algorithm/string.hpp"
+#include "boost/filesystem/path.hpp"
 
 using namespace IECore;
 using namespace IECoreScene;
@@ -104,7 +103,7 @@ SceneInterfacePtr SceneInterface::create( const std::s
 {
 	SceneInterfacePtr result = nullptr;
 
-	std::string extension = boost::filesystem::extension(path);
+	std::string extension = boost::filesystem::path(path).extension().string();
 	boost::algorithm::to_lower( extension );
 	IndexedIO::OpenModeFlags openMode = IndexedIO::OpenModeFlags( mode & (IndexedIO::Read|IndexedIO::Write|IndexedIO::Append) );
 	std::pair< std::string, IndexedIO::OpenModeFlags > key( extension, openMode );

--- src/IECoreScene/SceneInterface.cpp.orig	2025-02-25 10:37:21 UTC
+++ src/IECoreScene/SceneInterface.cpp
@@ -34,7 +34,7 @@
 
 #include "IECoreScene/SceneInterface.h"
 
-#include "boost/filesystem/convenience.hpp"
+#include "boost/filesystem/path.hpp"
 #include "boost/tokenizer.hpp"
 #include "boost/algorithm/string.hpp"
 
@@ -104,7 +104,7 @@ SceneInterfacePtr SceneInterface::create( const std::s
 {
 	SceneInterfacePtr result = nullptr;
 
-	std::string extension = boost::filesystem::extension(path);
+	std::string extension = boost::filesystem::path(path).extension().string();
 	boost::algorithm::to_lower( extension );
 	IndexedIO::OpenModeFlags openMode = IndexedIO::OpenModeFlags( mode & (IndexedIO::Read|IndexedIO::Write|IndexedIO::Append) );
 	std::pair< std::string, IndexedIO::OpenModeFlags > key( extension, openMode );

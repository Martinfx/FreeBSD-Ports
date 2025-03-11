--- src/GafferScene/Cryptomatte.cpp.orig	2025-03-02 22:40:44 UTC
+++ src/GafferScene/Cryptomatte.cpp
@@ -329,7 +329,7 @@ const std::string g_firstDataChannelSuffix = "00.R";
 };
 
 const std::string g_firstDataChannelSuffix = "00.R";
-const std::string g_cryptomatteChannelPattern = "^{}[0-9]+\\.[RGBA]";
+constexpr const std::string g_cryptomatteChannelPattern = "^{}[0-9]+\\.[RGBA]";
 
 Cryptomatte::Cryptomatte( const std::string &name )
 	: GafferImage::FlatImageProcessor( name )

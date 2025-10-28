--- src/GafferScene/Cryptomatte.cpp.orig	2025-10-10 20:24:55 UTC
+++ src/GafferScene/Cryptomatte.cpp
@@ -363,7 +363,7 @@ const std::string g_firstDataChannelSuffix = "00.R";
 };
 
 const std::string g_firstDataChannelSuffix = "00.R";
-const std::string g_cryptomatteChannelPattern = "^{}[0-9]+\\.[RGBA]";
+constexpr const std::string g_cryptomatteChannelPattern = "^{}[0-9]+\\.[RGBA]";
 
 Cryptomatte::Cryptomatte( const std::string &name )
 	: GafferImage::FlatImageProcessor( name )

--- src/IECore/SearchPath.cpp.orig	2024-11-26 17:25:35 UTC
+++ src/IECore/SearchPath.cpp
@@ -106,7 +106,7 @@ boost::filesystem::path SearchPath::find( const boost:
 boost::filesystem::path SearchPath::find( const boost::filesystem::path &file ) const
 {
 	// if it's a full path then there's no need to do any searching
-	if( file.is_complete() )
+	if( file.is_absolute() )
 	{
 		if( exists( file ) )
 		{

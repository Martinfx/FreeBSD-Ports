--- src/IECore/SearchPath.cpp.orig	2025-02-25 10:37:21 UTC
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

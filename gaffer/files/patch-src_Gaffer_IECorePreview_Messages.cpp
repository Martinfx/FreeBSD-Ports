--- src/Gaffer/IECorePreview/Messages.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/Gaffer/IECorePreview/Messages.cpp
@@ -79,7 +79,11 @@ void Messages::add( const Message &messa
 	m_nextBucket.push_back( message );
 	message.hash( m_hash );
 
-	++m_counts[ int(message.level) ];
+	// There is no count for `Level::Invalid`, which `count()` reports as 0.
+	if( message.level != IECore::MessageHandler::Level::Invalid )
+	{
+		++m_counts[ int(message.level) ];
+	}
 
 	if( m_nextBucket.size() == m_bucketSize )
 	{

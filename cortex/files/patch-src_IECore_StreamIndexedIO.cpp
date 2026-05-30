--- src/IECore/StreamIndexedIO.cpp.orig	2026-05-30 11:30:48 UTC
+++ src/IECore/StreamIndexedIO.cpp
@@ -2029,7 +2029,7 @@ NodeBase *StreamIndexedIO::Index::readNode( F &f )
 	}
 	else
 	{
-		throw IOException( fmt::format( "StreamIndexedIO::Index::readNode - Invalid EntryType found '{}'", nodeType ) );
+		throw IOException( fmt::format( "StreamIndexedIO::Index::readNode - Invalid EntryType found '{}'", static_cast<int>(nodeType) ) );
 	}
 }
 

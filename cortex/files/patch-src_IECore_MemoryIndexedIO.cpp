--- src/IECore/MemoryIndexedIO.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECore/MemoryIndexedIO.cpp
@@ -133,7 +133,10 @@
 	size_t size = 0;
 	if ( buf )
 	{
-		bufPtr = &(buf->readable()[0]);
+		// Note that we must not use `&buf->readable()[0]` here : the buffer
+		// may legitimately be empty, and hardened C++ standard libraries
+		// abort on out-of-range `operator[]` access.
+		bufPtr = buf->readable().data();
 		size = buf->readable().size();
 	}
 	open( new StreamFile( bufPtr, size, mode ), root );

--- src/GafferImage/DiskBlur.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferImage/DiskBlur.cpp
@@ -1522,7 +1522,10 @@ IECore::ConstObjectVectorPtr DiskBlur::c
 		int curSlope = queueStart - queueStop;
 
 		float nextDistance;
-		if( queueStop < queueStart && quadrantDistances[ queueStop ] + 1.0f <= quadrantDistances[ queueStart ] )
+		// Once every distance has entered the queue, `queueStart` is out of range : don't
+		// read past the end of `quadrantDistances` ( which aborts with a hardened C++
+		// standard library ), and stop as the unchecked comparison usually did.
+		if( queueStop < queueStart && queueStart < quadrantDistances.size() && quadrantDistances[ queueStop ] + 1.0f <= quadrantDistances[ queueStart ] )
 		{
 			// The next corner is due to a pixel distance falling out of the queue
 			nextDistance = quadrantDistances[ queueStop ] + 1.0f;

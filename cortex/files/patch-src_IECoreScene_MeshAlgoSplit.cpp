--- src/IECoreScene/MeshAlgoSplit.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreScene/MeshAlgoSplit.cpp
@@ -317,10 +317,15 @@
 
 	if( remapSegmentIndices.size() )
 	{
-		// If we are already using the remapping, we need to apply the sort to the existing remapping
+		// If we are already using the remapping, we need to apply the sort to the existing remapping.
+		// Entries for data values which no index refers to are left at -1 : they are never read, and
+		// `applySort[ -1 ]` aborts with a hardened C++ standard library.
 		for( int &r : remapSegmentIndices )
 		{
-			r = applySort[ r ];
+			if( r != -1 )
+			{
+				r = applySort[ r ];
+			}
 		}
 	}
 	else

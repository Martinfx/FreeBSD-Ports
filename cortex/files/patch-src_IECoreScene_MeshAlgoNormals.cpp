--- src/IECoreScene/MeshAlgoNormals.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreScene/MeshAlgoNormals.cpp
@@ -192,9 +192,12 @@
 					int numVerts = verticesPerFace[faceId];
 					int faceStart = startPerFace[faceId];
 
+					// Note the use of `data()` : for the last face, the end of the
+					// range is one past the last element, and `operator[]` on that
+					// index aborts with a hardened C++ standard library.
 					faceNormals[faceId] = polygonNormal(
-						PolygonVertexIterator( &vertIds[faceStart], &points[0] ),
-						PolygonVertexIterator( &vertIds[faceStart + numVerts], &points[0] )
+						PolygonVertexIterator( vertIds.data() + faceStart, points.data() ),
+						PolygonVertexIterator( vertIds.data() + faceStart + numVerts, points.data() )
 					);
 				}
 			},

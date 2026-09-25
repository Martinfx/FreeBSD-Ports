--- src/GafferScene/IECoreScenePreview/MeshAlgoTessellate.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferScene/IECoreScenePreview/MeshAlgoTessellate.cpp
@@ -862,8 +862,10 @@ void tessellateVariable(
 	const int numBoundaryCoords = tessPattern.GetNumBoundaryCoords();
 	const int numInteriorCoords = numOutCoords - numBoundaryCoords;
 
-	const Imath::V2f *tessBoundaryCoords = &coords[0];
-	const Imath::V2f *tessInteriorCoords = &coords[numBoundaryCoords];
+	// Note the use of `data()` : there may be no interior coordinates, and
+	// `operator[]` on the end index aborts with a hardened C++ standard library.
+	const Imath::V2f *tessBoundaryCoords = coords.data();
+	const Imath::V2f *tessInteriorCoords = coords.data() + numBoundaryCoords;
 
 	if( setup.m_outIndicesWritable )
 	{

--- src/GafferScene/IECoreScenePreview/PrimitiveAlgo.cpp.orig	2026-09-25 06:15:48 UTC
+++ src/GafferScene/IECoreScenePreview/PrimitiveAlgo.cpp
@@ -250,11 +250,14 @@ inline void copyElements( const Data *so
 				assert( typedSource.size() >= sourceIndex + num );
 				assert( typedDest.size() >= destIndex + num );
 
+				// Note the use of `data()` in the following : `num` may be 0, with the
+				// indices at the end of the data, where `operator[]` aborts with a hardened
+				// C++ standard library.
 				if constexpr( std::is_same_v< DataType, V3fVectorData > )
 				{
 					GeometricData::Interpretation interp = typedSourceData->getInterpretation();
 					transformPrimVarValue(
-						&typedSource[ sourceIndex ], &typedDest[ destIndex ], num, matrix, normalMatrix, interp
+						typedSource.data() + sourceIndex, typedDest.data() + destIndex, num, matrix, normalMatrix, interp
 					);
 				}
 				else
@@ -531,16 +534,19 @@ public:
 		int startFaceVarying = accumInterpolation[ PrimitiveVariable::FaceVarying ][i];
 		int numFaceVarying = countInterpolation[ PrimitiveVariable::FaceVarying ][i];
 
-		const int *sourceVerticesPerFace = &mesh->verticesPerFace()->readable()[0];
-		int *resultVerticesPerFace = &m_resultVerticesPerFaceData->writable()[ startUniform ];
+		// Note the use of `data()` in the following : source meshes may be empty, and
+		// the start of the last one may be the end of the result, where `operator[]`
+		// aborts with a hardened C++ standard library.
+		const int *sourceVerticesPerFace = mesh->verticesPerFace()->readable().data();
+		int *resultVerticesPerFace = m_resultVerticesPerFaceData->writable().data() + startUniform;
 		Canceller::check( canceller );
 		for( int j = 0; j < numUniform; j++ )
 		{
 			*(resultVerticesPerFace++) = *(sourceVerticesPerFace++);
 		}
 
-		const int* sourceVertexIds = &mesh->vertexIds()->readable()[0];
-		int *resultVertexIds = &m_resultVertexIdsData->writable()[startFaceVarying];
+		const int* sourceVertexIds = mesh->vertexIds()->readable().data();
+		int *resultVertexIds = m_resultVertexIdsData->writable().data() + startFaceVarying;
 		Canceller::check( canceller );
 		for( int j = 0; j < numFaceVarying; j++ )
 		{
@@ -549,10 +555,10 @@ public:
 
 		if( m_resultCornerIdsData )
 		{
-			const int *sourceCornerIds = &mesh->cornerIds()->readable()[0];
-			const float *sourceCornerSharpnesses = &mesh->cornerSharpnesses()->readable()[0];
-			int *resultCornerIds = &m_resultCornerIdsData->writable()[ m_accumCorners[i] ];
-			float *resultCornerSharpnesses = &m_resultCornerSharpnessesData->writable()[ m_accumCorners[i] ];
+			const int *sourceCornerIds = mesh->cornerIds()->readable().data();
+			const float *sourceCornerSharpnesses = mesh->cornerSharpnesses()->readable().data();
+			int *resultCornerIds = m_resultCornerIdsData->writable().data() + m_accumCorners[i];
+			float *resultCornerSharpnesses = m_resultCornerSharpnessesData->writable().data() + m_accumCorners[i];
 			Canceller::check( canceller );
 			for( int j = 0; j < m_countCorners[i]; j++ )
 			{
@@ -563,10 +569,10 @@ public:
 
 		if( m_resultCreaseLengthsData )
 		{
-			const int *sourceCreaseLengths = &mesh->creaseLengths()->readable()[0];
-			const float *sourceCreaseSharpnesses = &mesh->creaseSharpnesses()->readable()[0];
-			int *resultCreaseLengths = &m_resultCreaseLengthsData->writable()[m_accumCreases[i]];
-			float *resultCreaseSharpnesses = &m_resultCreaseSharpnessesData->writable()[m_accumCreases[i]];
+			const int *sourceCreaseLengths = mesh->creaseLengths()->readable().data();
+			const float *sourceCreaseSharpnesses = mesh->creaseSharpnesses()->readable().data();
+			int *resultCreaseLengths = m_resultCreaseLengthsData->writable().data() + m_accumCreases[i];
+			float *resultCreaseSharpnesses = m_resultCreaseSharpnessesData->writable().data() + m_accumCreases[i];
 			Canceller::check( canceller );
 			for( int j = 0; j < m_countCreases[i]; j++ )
 			{
@@ -574,8 +580,8 @@ public:
 				*(resultCreaseSharpnesses++) = *(sourceCreaseSharpnesses++);
 			}
 
-			const int *sourceCreaseIds = &mesh->creaseIds()->readable()[0];
-			int *resultCreaseIds = &m_resultCreaseIdsData->writable()[m_accumCreaseIds[i]];
+			const int *sourceCreaseIds = mesh->creaseIds()->readable().data();
+			int *resultCreaseIds = m_resultCreaseIdsData->writable().data() + m_accumCreaseIds[i];
 			Canceller::check( canceller );
 			for( int j = 0; j < m_countCreaseIds[i]; j++ )
 			{
@@ -782,8 +788,9 @@ public:
 		int startUniform = accumInterpolation[ PrimitiveVariable::Uniform ][i];
 		int numUniform = countInterpolation[ PrimitiveVariable::Uniform ][i];
 
-		int *resultVerticesPerCurve = &m_resultVerticesPerCurveData->writable()[ startUniform ];
-		const int *sourceVerticesPerCurve = &curves->verticesPerCurve()->readable()[0];
+		// Note the use of `data()`, as for meshes above.
+		int *resultVerticesPerCurve = m_resultVerticesPerCurveData->writable().data() + startUniform;
+		const int *sourceVerticesPerCurve = curves->verticesPerCurve()->readable().data();
 		Canceller::check( canceller );
 		for( int j = 0; j < numUniform; j++ )
 		{
@@ -1297,7 +1304,7 @@ IECoreScene::PrimitivePtr mergePrimitive
 
 						// We always leave one data element for primitives that don't have the relevant
 						// primvar, so just write out all indices pointing to that element.
-						int *destIndices = &destVar.indices->writable()[ startIndex ];
+						int *destIndices = destVar.indices->writable().data() + startIndex;
 						for( size_t j = 0; j < numIndices; j++ )
 						{
 							*(destIndices++) = dataStart;
@@ -1313,7 +1320,7 @@ IECoreScene::PrimitivePtr mergePrimitive
 						if( varInfo.indexed )
 						{
 							Canceller::check( canceller );
-							int *destIndices = &destVar.indices->writable()[ startIndex ];
+							int *destIndices = destVar.indices->writable().data() + startIndex;
 
 							copyIndices(
 								sourceVar.indices ? &sourceVar.indices->readable() : nullptr, destIndices,

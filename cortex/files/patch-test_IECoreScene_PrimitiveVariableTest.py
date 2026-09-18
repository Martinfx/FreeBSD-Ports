--- test/IECoreScene/PrimitiveVariableTest.py.orig	2026-09-10 21:49:58 UTC
+++ test/IECoreScene/PrimitiveVariableTest.py
@@ -176,7 +176,9 @@
 		p = IECoreScene.PrimitiveVariable(
 			IECoreScene.PrimitiveVariable.Interpolation.FaceVarying,
 			IECore.V3fVectorData( [ imath.V3f( x ) for x in range( 0, 3 ) ], IECore.GeometricData.Interpretation.Point ),
-			IECore.IntVectorData( [ 1, 2, 3, 1, 2, 3 ] )
+			# Note : the data has 3 elements, so 3 is not a valid index. Expanding it
+			# read out of bounds, which aborts with a hardened C++ standard library.
+			IECore.IntVectorData( [ 0, 1, 2, 0, 1, 2 ] )
 		)
 
 		self.assertEqual( p.expandedData().getInterpretation(), p.data.getInterpretation() )

--- src/IECoreImage/HdrMergeOp.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImage/HdrMergeOp.cpp
@@ -181,13 +181,13 @@
 		}
 	}
 
-	const T *ptrInR = &(inR->readable()[0]);
-	const T *ptrInG = &(inG->readable()[0]);
-	const T *ptrInB = &(inB->readable()[0]);
-	float *ptrOutR = &(outR->writable()[0]);
-	float *ptrOutG = &(outG->writable()[0]);
-	float *ptrOutB = &(outB->writable()[0]);
-	float *ptrOutA = &(outA->writable()[0]);
+	const T *ptrInR = inR->readable().data();
+	const T *ptrInG = inG->readable().data();
+	const T *ptrInB = inB->readable().data();
+	float *ptrOutR = outR->writable().data();
+	float *ptrOutG = outG->writable().data();
+	float *ptrOutB = outB->writable().data();
+	float *ptrOutA = outA->writable().data();
 
 	for ( size_t i = 0; i < pixelCount; i++ )
 	{
@@ -279,10 +279,10 @@
 
 	// normalize the outputs
 	float adjustment = pow( 2.0f, -exposureAdjustment );
-	float *ptrOutR = &(outR->writable()[0]);
-	float *ptrOutG = &(outG->writable()[0]);
-	float *ptrOutB = &(outB->writable()[0]);
-	float *ptrOutA = &(outA->writable()[0]);
+	float *ptrOutR = outR->writable().data();
+	float *ptrOutG = outG->writable().data();
+	float *ptrOutB = outB->writable().data();
+	float *ptrOutA = outA->writable().data();
 
 	for ( size_t i = 0; i < pixelCount; i++ )
 	{

--- src/GafferImage/Grade.cpp.orig	2026-09-25 07:03:08 UTC
+++ src/GafferImage/Grade.cpp
@@ -263,7 +263,8 @@ void Grade::processChannelData( const Ga
 	const float invGamma = 1. / gamma;
 
 	// Get some useful pointers.
-	float *outPtr = &(outData->writable()[0]);
+	// `data()` rather than `&[0]`, because deep tiles may have no samples.
+	float *outPtr = outData->writable().data();
 	const float *END = outPtr + outData->writable().size();
 
 	while (outPtr != END)

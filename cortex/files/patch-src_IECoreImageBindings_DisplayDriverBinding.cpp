--- src/IECoreImageBindings/DisplayDriverBinding.cpp.orig	2026-09-10 21:49:58 UTC
+++ src/IECoreImageBindings/DisplayDriverBinding.cpp
@@ -71,7 +71,7 @@
 static void displayDriverImageData( DisplayDriverPtr dd, const Imath::Box2i &box, FloatVectorDataPtr data )
 {
 	ScopedGILRelease gilRelease;
-	dd->imageData( box, &(data->readable()[0]), data->readable().size() );
+	dd->imageData( box, data->readable().data(), data->readable().size() );
 }
 
 static void displayDriverImageClose( DisplayDriverPtr dd )

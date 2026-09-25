--- src/GafferTestModule/GafferTestModule.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferTestModule/GafferTestModule.cpp
@@ -73,8 +73,12 @@ static void testConcurrentAccessToSameIn
 
 static boost::python::tuple countContextHash32CollisionsWrapper( int entries, int mode, int seed )
 {
-	IECorePython::ScopedGILRelease gilRelease;
-	auto result = countContextHash32Collisions( entries, mode, seed );
+	std::tuple<int, int, int, int> result;
+	{
+		IECorePython::ScopedGILRelease gilRelease;
+		result = countContextHash32Collisions( entries, mode, seed );
+	}
+	// The GIL must be held to create the Python tuple for the result.
 	return boost::python::make_tuple( std::get<0>(result), std::get<1>(result), std::get<2>(result), std::get<3>(result) );
 }
 

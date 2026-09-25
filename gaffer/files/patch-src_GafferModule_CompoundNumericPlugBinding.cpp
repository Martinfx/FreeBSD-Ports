--- src/GafferModule/CompoundNumericPlugBinding.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferModule/CompoundNumericPlugBinding.cpp
@@ -66,10 +66,11 @@ std::string serialisationRepr( const T *
 
 	if( interpretation != IECore::GeometricData::None )
 	{
+		// Boost.Python 1.87 and later include the enclosing class in the
+		// repr of nested enums, so we build the repr from the name instead.
 		boost::python::object interpretationAsPythonObject( interpretation );
-		boost::python::object interpretationRepr = interpretationAsPythonObject.attr( "__repr__" )();
-		extraArgs = "interpretation = " + std::string( boost::python::extract<std::string>( interpretationRepr ) );
-		boost::replace_first( extraArgs, "_IECore", "GeometricData" );
+		boost::python::object interpretationName = interpretationAsPythonObject.attr( "name" );
+		extraArgs = "interpretation = IECore.GeometricData.Interpretation." + std::string( boost::python::extract<std::string>( interpretationName ) );
 
 		if( serialisation )
 		{

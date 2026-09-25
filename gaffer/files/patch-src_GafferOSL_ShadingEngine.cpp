--- src/GafferOSL/ShadingEngine.cpp.orig	2026-09-25 06:42:21 UTC
+++ src/GafferOSL/ShadingEngine.cpp
@@ -1716,7 +1716,8 @@ const T *varyingValue( const IECore::Com
 	const DataType *d = points->member<DataType>( name );
 	if( d )
 	{
-		return &(d->readable()[0]);
+		// `data()` rather than `&[0]`, because there may be no points to shade.
+		return d->readable().data();
 	}
 	else
 	{
@@ -2129,7 +2130,7 @@ IECore::CompoundDataPtr ShadingEngine::s
 	if( const V3fVectorData *pData = points->member<V3fVectorData>( "P" ) )
 	{
 		shadeParameters.numPoints = pData->readable().size();
-		shadeParameters.p = reinterpret_cast<const OSL::Vec3 *>( &(pData->readable()[0]) );
+		shadeParameters.p = reinterpret_cast<const OSL::Vec3 *>( pData->readable().data() );
 	}
 	else
 	{

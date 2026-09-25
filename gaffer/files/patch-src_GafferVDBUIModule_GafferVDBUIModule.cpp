--- src/GafferVDBUIModule/GafferVDBUIModule.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferVDBUIModule/GafferVDBUIModule.cpp
@@ -63,6 +63,14 @@ DataPtr dataFromVDB( T value )
 	return new TypedData<T>( value );
 }
 
+// OpenVDB 13 includes `HalfGrid` in `NumericGridTypes`, and unless it is
+// built with `OPENVDB_USE_IMATH_HALF`, its `half` type is not the Imath one
+// that Cortex's `HalfData` uses.
+DataPtr dataFromVDB( openvdb::math::half value )
+{
+	return new HalfData( half( static_cast<float>( value ) ) );
+}
+
 template<typename T>
 DataPtr dataFromVDB( const openvdb::math::Vec3<T> &value )
 {

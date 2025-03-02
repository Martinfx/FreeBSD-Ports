--- src/GafferModule/AnimationBinding.cpp.orig	2025-03-02 13:53:37 UTC
+++ src/GafferModule/AnimationBinding.cpp
@@ -130,7 +130,7 @@ std::string slopeRepr( const double slope )
 
 std::string slopeRepr( const double slope )
 {
-	return fmt::format( std::isinf( slope ) ? "float( '{:.9g}' )" : "{:.9g}", slope );
+	return fmt::format(fmt::runtime(std::isinf( slope ) ? "float( '{:.9g}' )" : "{:.9g}"), slope );
 }
 
 void setTieMode( Animation::Key &k, const Animation::TieMode mode )

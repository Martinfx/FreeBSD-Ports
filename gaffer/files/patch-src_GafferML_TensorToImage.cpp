--- src/GafferML/TensorToImage.cpp.orig	2026-09-26 22:42:14 UTC
+++ src/GafferML/TensorToImage.cpp
@@ -121,7 +121,8 @@ void dispatchTensorData( const Ort::Valu
 			functor( value.GetTensorData<Ort::BFloat16_t>() );
 			break;
 		default :
-			throw IECore::Exception( fmt::format( "Unsupported tensor data type \"{}\"", elementType ) );
+			// fmt 10 and later don't format enums implicitly.
+			throw IECore::Exception( fmt::format( "Unsupported tensor data type \"{}\"", static_cast<int>( elementType ) ) );
 	}
 }
 

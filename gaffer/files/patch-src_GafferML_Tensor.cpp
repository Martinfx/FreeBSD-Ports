--- src/GafferML/Tensor.cpp.orig	2026-09-26 22:42:14 UTC
+++ src/GafferML/Tensor.cpp
@@ -143,7 +143,8 @@ void dispatchTensorData( const Ort::Valu
 			// > implies that we shouldn't know that, let alone depend on it.
 			[[fallthrough]];
 		default :
-			throw IECore::Exception( fmt::format( "Unsupported element type {}", elementType ) );
+			// fmt 10 and later don't format enums implicitly.
+			throw IECore::Exception( fmt::format( "Unsupported element type {}", static_cast<int>( elementType ) ) );
 	}
 }
 

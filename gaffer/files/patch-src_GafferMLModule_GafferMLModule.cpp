--- src/GafferMLModule/GafferMLModule.cpp.orig	2026-09-26 22:42:14 UTC
+++ src/GafferMLModule/GafferMLModule.cpp
@@ -154,7 +154,8 @@ object tensorGetItem( const Tensor &tens
 		case ONNX_TENSOR_ELEMENT_DATA_TYPE_STRING :
 			return object( tensor.value().GetStringTensorElement( toLinearIndex( tensor.shape(), location ) ) );
 		default :
-			throw IECore::Exception( fmt::format( "Unsupported element type {}", elementType ) );
+			// fmt 10 and later don't format enums implicitly.
+			throw IECore::Exception( fmt::format( "Unsupported element type {}", static_cast<int>( elementType ) ) );
 	}
 }
 

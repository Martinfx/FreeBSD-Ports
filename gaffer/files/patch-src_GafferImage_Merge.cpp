--- src/GafferImage/Merge.cpp.orig	2026-09-24 19:41:12 UTC
+++ src/GafferImage/Merge.cpp
@@ -201,7 +201,7 @@ typename Functor::ReturnType dispatchOpe
 		case Merge::Min : return functor.template operator()<OpMin>( std::forward<Args>( args )... );
 		case Merge::Max : return functor.template operator()<OpMax>( std::forward<Args>( args )... );
 		default:
-			throw InvalidArgumentException( fmt::format( "Invalid Merge Operation : {}", op ) );
+			throw InvalidArgumentException( fmt::format( "Invalid Merge Operation : {}", static_cast<int>( op ) ) );
 	}
 }
 

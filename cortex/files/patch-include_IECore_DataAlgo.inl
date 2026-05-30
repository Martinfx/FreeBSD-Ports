--- include/IECore/DataAlgo.inl.orig	2026-05-12 16:34:12 UTC
+++ include/IECore/DataAlgo.inl
@@ -206,7 +206,7 @@ typename std::invoke_result_t<F, Data *, Args&&...> di
 		case PathMatcherDataTypeId :
 			return functor( static_cast<PathMatcherData *>( data ), std::forward<Args>( args )... );
 		default :
-			throw InvalidArgumentException( fmt::format( "Data has unknown type '{}' / '{}'", typeId, data->typeName() ) );
+			throw InvalidArgumentException( fmt::format( "Data has unknown type '{}' / '{}'", static_cast<int>(typeId), data->typeName() ) );
 	}
 }
 
@@ -366,7 +366,7 @@ typename std::invoke_result_t<F, const Data *, Args&&.
 		case PathMatcherDataTypeId :
 			return functor( static_cast<const PathMatcherData *>( data ), std::forward<Args>( args )... );
 		default :
-			throw InvalidArgumentException( fmt::format( "Data has unknown type '{}' / '{}'", typeId, data->typeName() ) );
+			throw InvalidArgumentException( fmt::format( "Data has unknown type '{}' / '{}'", static_cast<int>(typeId), data->typeName() ) );
 	}
 }
 

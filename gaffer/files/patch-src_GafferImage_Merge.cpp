--- src/GafferImage/Merge.cpp.orig	2025-03-02 23:54:07 UTC
+++ src/GafferImage/Merge.cpp
@@ -181,6 +181,18 @@ struct OpMax
 	static const SingleInputMode onlyB = Operate;
 };
 
+std::string toString(GafferImage::Merge::Operation op)
+{
+    switch (op)
+    {
+        case GafferImage::Merge::Add: return "Add";
+        case GafferImage::Merge::Subtract: return "Subtract";
+        case GafferImage::Merge::Multiply: return "Multiply";
+        case GafferImage::Merge::Divide: return "Divide";
+        default: return "Unknown";
+    }
+}
+
 template< class Functor, typename... Args >
 typename Functor::ReturnType dispatchOperation( Merge::Operation op, Functor &&functor, Args&&... args )
 {
@@ -201,7 +213,7 @@ typename Functor::ReturnType dispatchOperation( Merge:
 		case Merge::Min : return functor.template operator()<OpMin>( std::forward<Args>( args )... );
 		case Merge::Max : return functor.template operator()<OpMax>( std::forward<Args>( args )... );
 		default:
-			throw InvalidArgumentException( fmt::format( "Invalid Merge Operation : {}", op ) );
+			throw InvalidArgumentException( fmt::format( "Invalid Merge Operation : {}", toString(op)) );
 	}
 }
 

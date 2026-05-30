--- include/IECoreScene/Primitive.inl.orig	2026-05-30 12:23:02 UTC
+++ include/IECoreScene/Primitive.inl
@@ -61,7 +61,7 @@ Primitive::variableIndexedView( const std::string &nam
 			throw IECore::InvalidArgumentException(
 				fmt::format(
 					"Primitive::variableIndexedView - PrimVar '{}' interpolation ({}) doesn't match requiredInterpolation ({})",
-					name, it->second.interpolation, requiredInterpolation
+					name, fmt::underlying(it->second.interpolation), fmt::underlying(requiredInterpolation)
 				)
 			);
 		}

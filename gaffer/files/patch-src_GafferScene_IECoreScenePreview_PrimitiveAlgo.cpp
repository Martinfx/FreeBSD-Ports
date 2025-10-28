--- src/GafferScene/IECoreScenePreview/PrimitiveAlgo.cpp.orig	2025-10-10 20:24:55 UTC
+++ src/GafferScene/IECoreScenePreview/PrimitiveAlgo.cpp
@@ -1417,6 +1417,16 @@ void PrimitiveAlgo::transformPrimitive(
 	}
 }
 
+template <>
+struct fmt::formatter<IECore::TypeId> {
+    constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }
+
+    template <typename FormatContext>
+    auto format(const IECore::TypeId& typeId, FormatContext& ctx) {
+        return fmt::format_to(ctx.out(), "{}", static_cast<int>(typeId)); // nebo typeId.str()
+    }
+};
+
 IECoreScene::PrimitivePtr PrimitiveAlgo::mergePrimitives(
 	const std::vector< std::pair< const IECoreScene::Primitive*, Imath::M44f > > &primitives,
 	const IECore::Canceller *canceller
@@ -1448,7 +1458,7 @@ IECoreScene::PrimitivePtr PrimitiveAlgo::mergePrimitiv
 	else
 	{
 		throw IECore::Exception( fmt::format(
-			"Unsupported Primitive type for merging: {}", primitives[0].first->typeId()
+			 "Unsupported Primitive type for merging: {}", static_cast<int>(primitives[0].first->typeId())
 		) );
 	}
 }
